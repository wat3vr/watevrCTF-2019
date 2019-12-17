from pwn import *
import time

def solve(ip, port, flag):
    r = remote(ip, int(port))
    r.sendline("Sj/rnuggbprzuir e/s-*en*bq*zz/ vssayv_ny_tr_. _gj_kv_gg__u__ __v__a__q__r__k___________________________________________________________________________0")
    time.sleep(1)
    a = r.recv()
    print(a)
    if flag in str(a):
        exit(0)
    else:
        exit(1)
flag = input("Flag: ").replace("\n", "")
ip, port = input("service: ").split(":")
solve(str(ip), int(port), str(flag))
