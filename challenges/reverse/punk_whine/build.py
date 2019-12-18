import random
import os
import shutil
from backend import *

flag = input() or "watevr{we_have_hit_rock_bottom}"

while len(flag) < bits / 8:
    n = random.randrange(0, 31)
    if n == 10:
        n += 1
    flag += chr(n)

flag = encode(flag)
assert(flag < 2 ** bits)

i_small = bits // 2 + random.randrange(-2**13, 2**13)
i_big = i_small + 4206969 * bits

flag_enc = rev_xs_p(flag, i_small)
assert(xs_p(flag_enc, i_big) == flag)

code = open("punk_whine_base.pl").read()

code = code.replace("[[[--- N ---]]]", str(flag_enc))
code = code.replace("[[[--- I ---]]]", str(i_big))

if os.path.isdir("downloads"):
    shutil.rmtree("downloads")
os.mkdir("downloads")
open("downloads/punk_whine.pl", "w").write(code)
