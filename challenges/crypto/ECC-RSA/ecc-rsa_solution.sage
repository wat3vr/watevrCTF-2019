ans = raw_input()

## ECC params
lines = open("downloads/ecc-rsa.txt", "r").read().split("\n")
ecc_p = ZZ(lines[0].split(" ")[-1])
a = ZZ(lines[1].split(" ")[-1])
b = ZZ(lines[2].split(" ")[-1])

## RSA params
e = ZZ(lines[5].split(" ")[-1])
n = ZZ(lines[6].split(" ")[-1])
c = ZZ(lines[7].split(" ")[-1])

F.<t> = GF(ecc_p)
R.<x> = PolynomialRing(F)
f = x**5 + a*x**3 + b*x**2 - n**2

## Find roots
factors = f.factor()
for factor in factors:
	factor = factor[0]
	if factor.degree() == 1:
		prime = mod(-factor[0], ecc_p)
		prime = Integer(prime)
		if gcd(n, prime) != 1:
			p = prime
			q = n//prime

def hex_to_ascii(hex_str):
	hex_str = hex_str.replace("0x", "")
	if (len(hex_str) % 2):
		hex_str = "0" + hex_str
	out = ""
	for i in range(0, len(hex_str), 2):
		out += chr(int(hex_str[i] + hex_str[i+1], 16))

	return out

## RSA secret primes recovered
phi = (p - 1)*(q - 1)
temp = xgcd(e, phi)
d = Integer(mod(temp[1], phi))
m = power_mod(c, d, n)
m = hex_to_ascii(hex(m))

exit(m != ans)