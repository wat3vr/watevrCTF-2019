import requests
from bs4 import BeautifulSoup
import subprocess
import os

flag = input()

print("patching spl program...")
f = open("downloads/romeo")
code = f.read()
f.close()

index1 = code.index(" II.")
index2 = code.index("Juliet:\nRemember me.")
code = list(code)
code = code[: index2 - 2] + list(" Speak your mind.") + code[index2 - 2 :]
code = code[: index1 + 4 - 27] + code[index1 + 4 :]
patched_code = "".join(code)

f = open("patched.spl", "w")
f.write(patched_code)
f.close()

print("running spl program...")
p = subprocess.Popen(["./compile_and_run.sh", "patched.spl"], stdout=subprocess.PIPE)
recovered_flag = p.communicate()[0].decode()

os.remove("patched.spl")

if recovered_flag == flag:
    print("correct flag!")
else:
    print('flag missmatch "%s" "%s"' % (recovered_flag, flag))
    exit(1)
