import re
from backend import *

code = open("downloads/punk_whine.pl").read()
n = int(re.search("qq\\((\\d+)\\)", code).groups()[0])
i = int(re.search("\\$i=(\\d+)", code).groups()[0])

res = xs_p(n, i % bits)
res_s = decode(res)

flag_re = re.compile("watevr\{[^}]+\}")
s, e = flag_re.search(res_s).span()
flag = res_s[s:e]

real_flag = input()
if real_flag:
    exit(flag != real_flag)
else:
    print(flag)
