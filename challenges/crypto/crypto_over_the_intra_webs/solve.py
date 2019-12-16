def decrypt(ciphertext, key):
	out = ""
	for i in range(2, len(ciphertext)):
		out += chr((((ciphertext[i] ^ (key*ciphertext[i-2])) - ciphertext[i-1]) ^ (key + ciphertext[i-1]))//ciphertext[i-2])
	return out

def solve(flag):
	text = ''.join(open("downloads/conversation", "r").readlines())
	KEY = int(open("key", "r").readlines()[0].rstrip())
	messages = text.split("Content: ")[1:]
	messages = [decrypt([int(z) for z in x.split("Message from:")[0].split(" ")], KEY) for x in messages[:-1]]
	if flag in " ".join(messages):
		exit(0)
	else:
		exit(1)
flag = input("flag: ")
solve(flag)
