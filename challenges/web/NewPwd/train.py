import requests
import urllib.parse
import base64
import json
import io
import numpy as np
from PIL import Image
import cv2.cv2 as cv
from solve import *

def combine_and_show_alphabet():
    imgTop = np.empty((50, 0))
    imgBottom = np.empty((50, 0))
    for char in alphabet[:16]:
        imgTop = np.append(imgTop, np.min(trained_key[char], axis=0), axis=1)
    for char in alphabet[16:]:
        imgBottom = np.append(imgBottom, np.min(trained_key[char], axis=0), axis=1)
    img = np.rot90(np.append(np.rot90(imgTop), np.rot90(imgBottom), axis=1), 3)
    cv.imshow("alphabet", img)


combine_and_show_alphabet()

lastchar = 0
count = 0
cheat_amount = 0

while True:
    captcha = get_captcha()
    solution = list(captcha[2])
    captcha_no_overlay = remove_overlay(captcha)
    chars = []
    for i in range(5):
        chars.append(captcha_no_overlay[:, i * 40 : (i + 1) * 40])

    while len(chars) != 0:
        cv.imshow("character", chars[0])
        if cheat_amount <= 0:
            key = cv.waitKey(0)
        else:
            key = ord(solution[0].lower())
        if key not in [ord(char) for char in alphabet.lower()] + [8, 13, 27, 225]:
            continue
        if key == 8:  # backspace
            trained_key[lastchar].pop()
            combine_and_show_alphabet()
        elif key == 27:  # escape
            for char in alphabet:
                cv.imwrite("training/%s.png" % char, np.min(trained_key[char], axis=0))
            cv.destroyAllWindows()
            exit()
        elif key == 13:  # enter
            for char in alphabet:
                cv.imwrite("training/%s.png" % char, np.min(trained_key[char], axis=0))
        elif key == 225:  # left shift
            key = ord(solution[0].lower())
            cheat_amount = 10
        if key not in [8, 13, 27, 225]:
            trained_key[chr(key).upper()].append(chars[0])
            chars.pop(0)
            solution.pop(0)
            lastchar = chr(key).upper()
            combine_and_show_alphabet()
            count += 1
            cheat_amount -= 1
            print(count)
