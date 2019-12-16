import argparse
import os
import json
import subprocess
import sys
import docker
import requests
import re
import math
import time
import boto3
import botocore
import hashlib

flag_format = "watevr{%s}"
docker_repo = "redacted"
s3_bucket = "redacted"
directory_secret = "redacted"

challenge_dirs = []

for dirname, dirlist, filelist in os.walk("challenges"):
    if "challenge.json" in filelist:
        challenge_dirs.append(dirname)

challenges = []

for challenge_dir in challenge_dirs:
    with open(os.path.join(challenge_dir, "challenge.json")) as f:
        challenges.append(json.load(f))
        challenges[-1]["directory"] = challenge_dir

parser = argparse.ArgumentParser(
    description="Tools for creating ctf challenges and testing their validity"
)

parser.add_argument(
    "mode",
    type=str,
    help="build the challenge, start the challenge, or build, start and solve the challenge",
    choices=["build", "start", "validate", "make_graph"],
)

parser.add_argument(
    "challenge name",
    nargs=argparse.REMAINDER,
    type=str,
    help="the title of your challenge, as seen in challenge.json",
    choices=[chall["title"] for chall in challenges],
)

args = parser.parse_args()

travis = os.getenv("TRAVIS") == "true"

if args.mode == "make_graph":
    import matplotlib.pyplot as plt

    authors = {}
    for challenge in challenges:
        for author in challenge["authors"]:
            if author not in authors:
                authors[author] = 0
            authors[author] += 1

    categories = {}
    for challenge in challenges:
        if challenge["categories"][0] not in categories:
            categories[challenge["categories"][0]] = 0
        categories[challenge["categories"][0]] += 1

    fig, ax_lst = plt.subplots(1, 2)

    y_pos = range(len(authors))
    ax_lst[0].barh(y_pos, list(authors.values()))
    ax_lst[0].set_yticks(y_pos)
    ax_lst[0].set_yticklabels(authors.keys())

    y_pos = range(len(categories))
    ax_lst[1].barh(y_pos, list(categories.values()))
    ax_lst[1].set_yticks(y_pos)
    ax_lst[1].set_yticklabels(categories.keys())

    fig.tight_layout()

    fig.savefig("graph.png")
    exit(0)


def title_to_docker_name(title):
    title = title.replace(" ", "_")
    title = re.sub(r"[^A-Za-z0-9_.-]", "", title)
    title = title.lstrip("_.-")
    title = title.lower()
    return title

def main():
    try:
        matching_challenges = [
            chall
            for chall in challenges
            if chall["title"].lower()
            == " ".join(getattr(args, "challenge name")).lower()
        ]
        if len(matching_challenges) == 0:
            print("challenge not found")
            return 1
        if len(matching_challenges) > 1:
            print("multiple challenges with this name exist")
            return 1

        challenge = matching_challenges[0]

        print("\u001b[34;1mchallenge: " + challenge["title"] + "\u001b[0m")

        # validating challenge.json
        fields = {
            "flag": str,
            "append_random_data": bool,
            "follows_flag_format": bool,
            "categories": list,
            "authors": list,
            "title": str,
            "description": str,
            "uses_docker": bool,
            "website_services": list,
            "netcat_services": list,
            "build_script": str,
            "solve_script": str,
            "changeable_flag": bool,
            "unlocked_by": str,
        }
        required_fields = [
            "flag",
            "append_random_data",
            "follows_flag_format",
            "categories",
            "authors",
            "title",
            "description",
            "uses_docker",
            "build_script",
            "solve_script",
            "changeable_flag",
        ]
        for field in required_fields:
            if field not in challenge:
                print(f"field {field} in challenge.json is required.")
                return 1
            if fields[field] != bool and not challenge[field]:
                print(f"field {field} must not be empty")
                return 1
        for field in challenge.keys():
            if field in ["directory"]:
                continue
            if field not in fields:
                print(f"field {field} does not exist in the specification")
                return 1
            if type(challenge[field]) != fields[field]:
                print(f"field {field} type must be {fields[field]}")
                return 1
        if challenge.get("unlocked_by"):
            unlocked_by = [
                chall
                for chall in challenges
                if chall["title"].lower() == challenge["unlocked_by"].lower()
            ]
            if len(unlocked_by) == 0:
                print("unlocked_by challenge not found")
                return 1
            if len(unlocked_by) > 1:
                print("multiple unlocked_by challenges with this name exist")
                return 1

        assert not challenge["append_random_data"]

        if challenge["uses_docker"]:
            try:
                client = docker.from_env()
                client.images.list()
                tag = title_to_docker_name(challenge["title"])
            except requests.exceptions.ConnectionError:
                print("need root permissions to run docker (run with sudo)")
                return 1

        if args.mode != "start":
            flag = challenge["flag"]

            if challenge["append_random_data"]:
                flag += "_" + os.urandom(5).hex()

            if challenge["follows_flag_format"]:
                flag = flag_format % flag

            print("flag:", flag)

            print("building challenge...")

            try:
                os.mkdir(os.path.join(challenge["directory"], "downloads"))
            except FileExistsError:
                pass

            print("    running build script...")

            env = os.environ.copy()
            env["TEST"] = "true"

            p = subprocess.Popen(
                challenge["build_script"],
                stdout=sys.stdout if not travis else subprocess.PIPE,
                stdin=subprocess.PIPE,
                stderr=sys.stdout if not travis else subprocess.PIPE,
                cwd=challenge["directory"],
                shell=True,
                env=env,
            )

            out = p.communicate(
                input=flag.encode() if challenge["changeable_flag"] else None
            )
            if out[0]:
                print(out[0].decode())
            if out[1]:
                print(out[1].decode())

            if p.returncode != 0:
                print("    build script exited with a code other than 0")
                return 1

            if challenge["uses_docker"]:
                print("    building docker image...")
                client.images.build(
                    path=os.path.join(challenge["directory"], "container"),
                    tag=tag,
                    rm=True,
                )[0]
            else:
                print(
                    "    challenge doesn't use a docker container, skipping image creation"
                )

        if args.mode == "build":
            print("build done!")
            return 0

        print("starting challenge...")

        ports = {}

        if challenge["uses_docker"]:
            i = 0
            services = []
            for port in challenge.get("website_services", []):
                ports[port] = i + 50000
                services.append("http://127.0.0.1:%s" % ports[port])
                i += 1

            for port in challenge.get("netcat_services", []):
                ports[port] = i + 50000
                services.append("127.0.0.1:%s" % ports[port])
                i += 1

            container = client.containers.run(
                tag,
                ports=ports,
                detach=True,
                auto_remove=True,
                environment={"TEST": "true"},
            )
            if args.mode == "start":
                print("services hosted at:\n" + "\n".join(services))

                for log in container.logs(stream=True):
                    sys.stdout.write(log.decode())

        else:
            print("    challenge doesn't use a docker container, nothing to start")

        if args.mode == "start":
            return 0

        if challenge["uses_docker"]:
            time.sleep(5)  # give container time to boot

        print("solving challenge...")

        stdin = b""
        stdin += flag.encode()
        stdin += b"\n"
        if challenge["uses_docker"]:
            stdin += ("\n".join(services)).encode()

        env = os.environ.copy()
        env["TEST"] = "true"

        p = subprocess.Popen(
            challenge["solve_script"],
            stdout=sys.stdout if not travis else subprocess.PIPE,
            stdin=subprocess.PIPE,
            stderr=sys.stdout if not travis else subprocess.PIPE,
            cwd=challenge["directory"],
            shell=True,
            env=env,
        )
        out = p.communicate(input=stdin)
        if out[0]:
            print(out[0].decode())
        if out[1]:
            print(out[1].decode())

        if challenge["uses_docker"]:
            container.kill()
        if p.returncode != 0:
            print("    solve script exited with a code other than 0")
            return 1

        print("challenge solved")
        print(
            "your whole challenge including the challenge.json file is setup correctly and ready to go!"
        )
        return 0
    except KeyboardInterrupt:
        print("exiting...")
        if container:
            container.kill()

exit(main())
