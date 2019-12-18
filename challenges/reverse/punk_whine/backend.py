bits = 2**16

def pascal_2(a, b):
    # Lucas theorem with p = 2
    # Equiv. for every pair of bits if a and b, if a == 0 and b == 1 then pascal_2(a, b) = 0, else it's 1
    return (~a & b) == 0


def xs_p(n, p):
    res = 0
    for i in range(bits):
        if pascal_2(p, i):
            res ^= n << i
    return res % 2**bits


def decode(n):
    res = ""
    while n != 0:
        res += chr(n & 0xFF)
        n >>= 8
    return res


def encode(st):
    res = 0
    for ch in st[::-1]:
        res = (res << 8) | ord(ch)
    return res


def rev_xs_p(n, p):
    total_xor = 0
    res = 0
    pascalmask = 0
    for i in range(bits):
        if pascal_2(p, i):
            pascalmask |= 1 << i
    mmask = (1 << bits) - 1
    for i in range(bits):
        if (total_xor >> i) & 1 != (n >> i) & 1:
            res |= 1 << i
            total_xor ^= (pascalmask << i) & mmask
    return res
