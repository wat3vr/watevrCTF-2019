
def main(flag):
    f1 = open("chall.txt", "r").readlines()
    f2 = open("stargate.txt", "r").readlines()
    total = ""
    oddlines = []
    for i in range(0, len(f2)-1):
        if f2[i] != f1[i]:
            oddlines.append((f1[i], f2[i]))
    for odd in oddlines:
        for i in range(0, len(list(odd[0]))-1):
            if list(odd[0])[i] != list(odd[1])[i]:
                total += list(odd[0])[i]
                break
    print(total)
    if str(total) == str(flag):
        print("Correct!")
        exit(0)
    else:
        print("Incorrect!")
        exit(1)
main(input("flag: "))
