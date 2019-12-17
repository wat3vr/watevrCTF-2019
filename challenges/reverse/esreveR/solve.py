#!/usr/bin/env python3
from pwn import *
r = process("downloads/esrever")
r.sendline(input("flag: ").encode())
if "Congratulations!" in str(r.recvall()):
	exit(0)
else:
	exit(1)

'''
small writeup:
	some constants were calculated, namely -1709993534, 1556067285, -940414931, 194, 1115522582.
	with those the program xors, and it is possible to calculate all charecters knowing this.
'''
