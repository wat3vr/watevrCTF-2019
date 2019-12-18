#!/usr/bin/env python3
import subprocess
import os
import sys
import shutil

flag = input("Flag (empty for default): ").strip()
if flag == "":
    flag = "watevr{more_like_blockdane}"

envo = os.environ.copy()

cargo = subprocess.Popen(["which", "cargo"], stdout=subprocess.PIPE)
cargo.wait()
out = cargo.communicate()[0]
print(out)
if out == "":
    print("Need cargo!")
    exit()

envo["FLAGG"] = flag
print(envo["HOME"])
build_code = subprocess.Popen([envo["HOME"] + "/.cargo/bin/cargo", "+nightly", "build", "--release"], env=envo, cwd=os.getcwd() + "/code/")
build_code.wait()
print("Done")

try:
    shutil.rmtree("out")
except:
    pass

try:
    os.mkdir("container")
except:
    pass

try:
    os.mkdir("downloads")
except:
    pass

try:
    os.mkdir("downloads/src")
except Exception as e:
    pass

shutil.copy("code/target/release/code", "container/service")
shutil.copy("code/Cargo.toml", "downloads/Cargo.toml")
shutil.copy("code/src/main.rs", "downloads/src/main.rs")
shutil.copy("code/src/kæde.rs", "downloads/src/kæde.rs")

mine_code = open("code/src/mining.rs").readlines()
mine_code = mine_code[:3] + ["--- REDACTED ---\n"] + mine_code[103:]
open("downloads/src/mining.rs", "w").writelines(mine_code)

shutil.make_archive("downloads/src", "zip", "downloads/src")
shutil.rmtree("downloads/src")
