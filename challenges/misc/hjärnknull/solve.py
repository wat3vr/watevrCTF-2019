from pwn import *
import time

'''
https://github.com/kjcolley7/CTF-WriteUps/blob/master/2019/watevr/Hjarnknull/README.md
writeup by kcolley.
'''

res = ""
flag = input("flag: ").replace("\n", "")
ip, port = input("service: ").replace("\n", "").split(":")
q = process(["node", "solve.js"])
msg = str(q.readall().decode("utf-8")) 
r = remote(ip, port)
r.send(msg)
time.sleep(1)
while True:
	try:
		res += str(r.recv().decode("utf-8"))
	except:
		break
print(res)
if flag in res:
	exit(0)
exit(1)
