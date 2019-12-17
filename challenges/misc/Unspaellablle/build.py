import random
alphabet = "qwerttyuiopåasdfghjklöäzxcvbnm{}1234567890_"
def main(flag):
	replacedlinesList = [0]

	f = open("stargate.txt", "r")
	lines = f.readlines()
	#try:
	if True:
		for letter in list(flag):
			index = 0
			conv = 0
			while True:
				index = random.randint(0, int((len(lines)-1)*1/(len(list(flag))-(len(replacedlinesList)-1))))
				if (len([x for x in alphabet if x in lines[index]]) > 0) and (index > replacedlinesList[len(replacedlinesList)-1]):
					replacedlinesList.append(index)
					break
				else:
					if conv > 1000:
						main(flag)
						exit()
				conv += 1
			index2 = 0
			while True:
				index2 = random.randint(0, len(list(lines[index]))-1)
				if len([x for x in alphabet if x in list(lines[index])[index2]]): #the index was at one of the words
					break
			replacedLine = list(lines[index])
			replacedLine.insert(index2, letter)
			lines[index] = "".join(replacedLine)
			print("replaced line " + str(index) + " with " + str(lines[index]))
		with open("downloads/chall.txt", "w+") as res1:
			for line in lines:
				res1.write(str(line))
		with open("chall.txt", "w+") as res2:
			for line in lines:
				res2.write(str(line))
		print("Job's done")
	#except:
	#	print("EXCEPTION! - spellchall - script.py")
	#	exit(1)
main(input("flag: "))
exit(0)
