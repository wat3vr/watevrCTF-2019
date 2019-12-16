from fastecdsa.curve import P521 as Curve
from fastecdsa.point import Point
from Crypto.Util.number import bytes_to_long, isPrime
from os import urandom
from random import getrandbits

def gen_rsa_primes(G):
	urand = bytes_to_long(urandom(521//8))
	while True:
		s = getrandbits(521) ^ urand

		Q = s*G
		if isPrime(Q.x) and isPrime(Q.y):
			print("ECC Private key:", hex(s))
			print("RSA primes:", hex(Q.x), hex(Q.y))
			print("Modulo:", hex(Q.x * Q.y))
			return (Q.x, Q.y)


flag = int.from_bytes(input(), byteorder="big")

ecc_p = Curve.p
a = Curve.a
b = Curve.b

Gx = Curve.gx
Gy = Curve.gy
G = Point(Gx, Gy, curve=Curve)


e = 0x10001
p, q = gen_rsa_primes(G)
n = p*q


file_out = open("downloads/ecc-rsa.txt", "w")

file_out.write("ECC Curve Prime: " + hex(ecc_p) + "\n")
file_out.write("Curve a: " + hex(a) + "\n")
file_out.write("Curve b: " + hex(b) + "\n")
file_out.write("Gx: " + hex(Gx) + "\n")
file_out.write("Gy: " + hex(Gy) + "\n")

file_out.write("e: " + hex(e) + "\n")
file_out.write("p * q: " + hex(n) + "\n")

c = pow(flag, e, n)
file_out.write("ciphertext: " + hex(c) + "\n")