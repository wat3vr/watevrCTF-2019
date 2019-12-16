import re
from urllib.parse import unquote
import itertools
from pwn import *

# this script just checks the solution works. the actual solution is to by trial and error manually figure out the function that converts the response body into the path

flag = input().rstrip("\n")
service = input()

target_path = "i_store_my_flag_inside_this_file.txt"


conn = remote(*service.split("//")[1].split(":")[:2])
conn.write(b"HTTP/1.1 200 OK\r\nContent-Length: %s\r\n\r\n%s" % (str(len(flag)).encode(), flag.encode()))
response = conn.readline()
path = unquote(re.match(r"POST /(.+) HTTP/1.1", response.decode()).group(1))
print(path)

if path != target_path:
    exit(1)
