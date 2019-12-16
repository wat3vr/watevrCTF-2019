ans = raw_input()

lines = open("downloads/polynomial_rsa.txt", "r").readlines()
p = Integer(lines[0][7:-1])

## Univariate Polynomial Ring in y over Finite Field of size p
R.<y> = PolynomialRing(GF(p))

N = R(lines[1][9:-1])
S.<x> = R.quotient(N)

P, Q = N.factor()
P = P[0]
Q = Q[0]

e = 65537

## Number of elements with a multiplicative inverse in the polynomial ring, analogous to phi(n) for normal RSA
s = (p^P.degree() - 1)*(p^Q.degree() - 1)
d = inverse_mod(e, s)

c = S(lines[2][12:])
m = c^d

flag = bytearray(list(m)).replace("\0", "")
exit(flag != ans)
