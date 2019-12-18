import os, shutil

from git import Repo

# TODO: Custom flag
flag = input("Flag (empty for default): ").strip()
if flag == "":
    flag = "watevr{everything_is_offentligt}"

# Create repo

REPO_PATH = "container/generated_repo"

if os.path.isdir(REPO_PATH):
    shutil.rmtree(REPO_PATH)

os.mkdir(REPO_PATH)

repo = Repo.init(REPO_PATH)

for f in "web_server.py", "folder.html":
    shutil.copy(os.path.join("web_files", f), os.path.join(REPO_PATH, f))
    repo.index.add([f])

commit_messages = open("index_revisions/messages.txt", "r").read().strip().split("\n")

for i, msg in enumerate(commit_messages):
    shutil.copy(os.path.join("index_revisions", f"{i}.html"), os.path.join(REPO_PATH, "index.html"))
    repo.index.add(["index.html"])

    if i == 1:
        # Special commit with flag
        with open(os.path.join(REPO_PATH, "flag.txt"), "w") as f:
            f.write(flag)
        repo.index.add(["flag.txt"])

    if i == 2:
        repo.index.remove(["flag.txt"])
        os.unlink(os.path.join(REPO_PATH, "flag.txt"))

    repo.index.commit(msg)
