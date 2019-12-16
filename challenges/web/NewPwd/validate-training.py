from PIL import Image, ImageDraw, ImageFont
import random
import numpy as np
from solve import *
import os
import cv2.cv2 as cv
os.chdir("container")
from container.server import *

print("testing solver...")
# results = []
# for i in range(100):
#     captcha = get_captcha()
#     results.append(solve_captcha(captcha) == captcha[2])
#     if not results[-1]:
#         cv.imshow("1", captcha[0])
#         print(solve_captcha(captcha))
#         break

# print(sum(results)/len(results))

results = []
for i in range(1000):
    file, captcha_id, captcha_type, captcha_text = generate_captcha()
    captcha = (cv.cvtColor(np.array(Image.open(file)), cv.COLOR_BGR2GRAY), captcha_type)
    results.append(solve_captcha(captcha) == captcha_text)
#     if not results[-1]:
#         cv.imshow("2", captcha[0])
#         print(solve_captcha(captcha))
#         break

print(sum(results)/len(results))

cv.waitKey(0)
cv.destroyAllWindows()