from sage.stats.distributions.discrete_gaussian_polynomial import DiscreteGaussianDistributionPolynomialSampler as d_gauss

flag = bytearray(raw_input())
flag = list(flag)

n = len(flag)
q = 40961

## Finite Field of size q. 
F = GF(q)

## Univariate Polynomial Ring in y over Finite Field of size q
R.<y> = PolynomialRing(F)

## Univariate Quotient Polynomial Ring in x over Finite Field of size 40961 with modulus b^n + 1
S.<x> = R.quotient(y^n + 1)

def gen_small_poly():
    sigma = 2/sqrt(2*pi)
    d = d_gauss(S, n, sigma)
    return d()

def gen_large_poly():
    return S.random_element()


## Public key 1
a = gen_large_poly()

## Secret key
s = S(flag)


file_out = open("downloads/public_keys.txt", "w")
file_out.write("a: " + str(a) + "\n")


for i in range(100):
    ## Error
    e = gen_small_poly()

    ## Public key 2
    b = a*s + e
    file_out.write("b: " + str(b) + "\n")

file_out.close()
