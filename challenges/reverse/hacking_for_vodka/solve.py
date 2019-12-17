from pwn import *
r = process("./downloads/vodka")
r.sendline(str(input("flag: ")))
if "congratulations" in str(r.recvall()):
	r.close()
	exit(0)
else:
	print("incorrect flag!")
	r.close()
	exit(1)

'''
super small writeup:
	there was a scrambled alphabet, it xored chars from the alhabet to build the flag aslong as a debugger was not attached
	you could calculate what the flag was by hand or by pathcing the binary to bypass strcmp.
'''
