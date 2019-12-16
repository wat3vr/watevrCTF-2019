flag = bytearray(raw_input())
flag = list(flag)
length = len(flag)
bits = 16

## Prime for Finite Field.
p = random_prime(2^bits-1, False, 2^(bits-1))

file_out = open("downloads/polynomial_rsa.txt", "w")
file_out.write("Prime: " + str(p) + "\n")

## Univariate Polynomial Ring in y over Finite Field of size p
R.<y> = PolynomialRing(GF(p))

## Analogous to the primes in Z
def gen_irreducable_poly(deg):
    while True:
        out = R.random_element(degree=deg)
        if out.is_irreducible():
            return out


## Polynomial "primes"
P = gen_irreducable_poly(ZZ.random_element(length, 2*length))
Q = gen_irreducable_poly(ZZ.random_element(length, 2*length))

## Public exponent key
e = 65537

## Modulus
N = P*Q
file_out.write("Modulus: " + str(N) + "\n")

## Univariate Quotient Polynomial Ring in x over Finite Field of size 659 with modulus N(x)
S.<x> = R.quotient(N)

## Encrypt
m = S(flag)
c = m^e

file_out.write("Ciphertext: " + str(c))
file_out.close()