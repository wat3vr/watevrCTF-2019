from pwn import *

flag = input("flag: ").replace("\n", "")


r = gdb.debug("downloads/timeout", '''
br _start
continue

set {int}0x60105c = 1337
set $pc = 0x4006a6
continue
''')

res = str(r.recv())

print(res)

if flag in res:
    exit(0)
exit(1)