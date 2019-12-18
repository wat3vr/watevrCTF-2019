import string
import random
import sympy as sp
import math

chars = string.ascii_lowercase + string.ascii_uppercase + string.digits + "{}_"

nr_per_page = 7
nr_st = len(chars) ** nr_per_page

m = sp.nextprime(nr_st)

def n2st(n, amount_of_digits = nr_per_page):
    if amount_of_digits == 0:
        return ""
    ch = chars[n % len(chars)]
    return n2st(n // len(chars), amount_of_digits - 1) + ch

def st2n(st, amount_of_digits = nr_per_page):
    if amount_of_digits == 0:
        return 0

    dig = chars.index(st[amount_of_digits - 1])
    return dig + st2n(st, amount_of_digits-1) * len(chars)

def exp_mod(a, b):
    if b == 0:
        return 1
    if b % 2 == 0:
        return (exp_mod(a, b / 2) ** 2) % m
    return (a * exp_mod(a, b // 2) ** 2) % m

def inv(a):
    return exp_mod(a % m, m - 2)

# https://stackoverflow.com/a/37237257/1753929
# log_a b (mod p)
def log_mod(a,b,p = m,N = None):
    if not N: N = 1 + int(math.sqrt(p))

    #initialize baby_steps table
    baby_steps = {}
    baby_step = 1
    for r in range(N+1):
        baby_steps[baby_step] = r
        baby_step = baby_step * a % p

    #now take the giant steps
    giant_stride = pow(a,(p-2)*N,p)
    giant_step = b
    for q in range(N+1):
        if giant_step in baby_steps:
            return q*N + baby_steps[giant_step]
        else:
            giant_step = giant_step * giant_stride % p
    return "No Match"

def get_ack(A, B, C, N):
    # Flag: A B C at given N
    # f(N) = A   (1)
    # f(N+1) = B (2)
    # f(N+2) = C (3)

    # Enligt WA:
    # delta = 1 / (A - 2B + C)
    # a = (B - C) / (A - B)
    # c * a^N = (A^2 - 2AB + B^2) * delta
    # c = (A^2 - 2AB + B^2) * delta * a^(-N)
    # k = (AC - B^2) * delta


    delta = inv(A - 2 * B + C)
    a = ((B - C) * inv(A - B)) % m
    c = ((A ** 2 - 2 * A * B + B ** 2) * delta * inv(exp_mod(a, N))) % m
    k = ((A * C - B ** 2) * delta) % m

    return a, c, k

def gcd(a, b):
    if a == b:
        return a
    if a > b:
        return gcd(b, a)
    return gcd(a, b - a)

# f(x) = c * a ^ x + k
def f(n, a, c, k):
    if n == 0:
        return (c + k) % m
    if n % 2 == 0:
        fx = f(n // 2, a, c, k)
        return (k + (fx ** 2 - 2 * k * fx + k ** 2) * c_inv) % m
    else:
        fx = f((n - 1) // 2, a, c, k)
        return (k + a * (fx ** 2 - 2 * k * fx + k ** 2) * c_inv) % m

def f_inv(fx, a, c, k):
    c_inv = inv(c)
    ex = ((fx - k) * c_inv) % m
    return log_mod(a, ex)

if __name__ == "__main__":
    A = st2n("watevr{")
    B = st2n("S10P_B4")
    C = st2n("BBL1NG}")
    N = random.randrange(m // 2, m)
    a, c, k = get_ack(A, B, C, N)

    flag_idx = f_inv(st2n("watevr{"), a, c, k)
    flag_idx

    for i in range(flag_idx - 3, flag_idx + 6):
        print(n2st(f(i, a, c, k)), end=" ")

