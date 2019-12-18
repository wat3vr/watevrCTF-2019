import back
import requests

real_flag = input()
url = input()

first = str(requests.get(url + "/view?page=0").content, "utf-8")
first_page = first.split('class="page">')[1].split("<br")[0].strip()
lst = list(map(back.st2n, first_page.split()))

a, c, k = back.get_ack(*lst[:3], 0)
idx = back.f_inv(back.st2n("watevr{"), a, c, k)

print("Flag at:", idx)

flag_url = url + "/view?page=" + str(idx // 100) + "&offset=" + str(idx % 100)

print("At url:", flag_url)

flag_site = str(requests.get(flag_url).content, "utf-8")
first_page = flag_site.split('class="page">')[1].split("<br")[0].strip()

flag_all = "".join(first_page.split(" "))
flag = flag_all.split("}")[0] + "}"

if flag == real_flag:
    exit(0)
else:
    exit(1)
