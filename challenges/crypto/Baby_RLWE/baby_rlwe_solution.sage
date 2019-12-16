ans = raw_input()

keys = open("downloads/public_keys.txt", "r").read().split("\n")[:-1]

temp1 = keys[0].find("^") 
temp2 = keys[0].find(" ", temp1)

n = Integer(keys[0][temp1+1:temp2]) + 1
q = 40961


F = GF(q)
R.<y> = PolynomialRing(F)
S.<x> = R.quotient(y^n + 1)


a = S(keys[0].replace("a: ", ""))


keys = keys[1:]

counters = []
for i in range(n):
    counters.append({})


for key in keys:
    b = key.replace("b: ", "")
    b = list(S(b))
    for i in range(n):
        try:
            counters[i][b[i]] += 1
        except:
            counters[i][b[i]] = 1

a_s = []
for counter in counters:
    dict_keys = counter.keys()
    max_key = 0
    maxi = 0
    for key in dict_keys:
        if counter[key] > maxi:
            maxi = counter[key]
            max_key = key

    a_s.append(max_key)

a_s = S(a_s)
s = a_s/a

try:
    flag = bytearray(list(s))
except Exception as err:
    exit(1)

exit(flag != ans)