import shutil, os
import random
from back import get_ack, chars, m, inv, st2n

flag = input() or "watevr{S10P_B4BBLING}"

if len(flag) != 21:
    print("Flag has to have the length 21")
    exit(1)

A = st2n(flag[:7])
B = st2n(flag[7:14])
C = st2n(flag[14:])
N = random.randrange(m // 2, m)
a, c, k = get_ack(A, B, C, N)

if not os.path.isdir("container"):
    os.mkdir("container")

for old_file in "backend.py", "web.py", "keys.py":
    path = os.path.join("container", old_file)
    if os.path.isfile(path):
        os.remove(path)


out = open("container/backend.py", "w")

out.write(f"""\
chars = {repr(chars)}

c, a, k, d = map(int, open("keys.txt", "r").read().split())
m = {m}
assert((c * d) % m == 1);

def n2st(n, length = 7):
    if length == 0:
        return ""
    ch = chars[n % len(chars)]
    return n2st(n // len(chars), length - 1) + ch

def f(n):
    if n == 0:
        return (c + k) % m
    if n % 2 == 0:
        fx = f(n // 2)
        return (k + (fx ** 2 - 2 * k * fx + k ** 2) * d) % m
    else:
        fx = f((n - 1) // 2)
        return (k + a * (fx ** 2 - 2 * k * fx + k ** 2) * d) % m

if __name__ == "__main__":
    while True:
        print(n2st(f(int(input()))))
""")

out.close()

out = open("container/keys.txt", "w")
out.write(f"{c} {a} {k} {inv(c)}")

shutil.copyfile("website_template.py", "container/web.py")
