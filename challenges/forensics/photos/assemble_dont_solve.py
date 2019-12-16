import os
import cv2.cv2 as cv
import numpy as np
import re
import subprocess

collage = np.zeros((1, 1, 3), dtype=np.int8)
pattern = re.compile(r"X Position[^\d]+(\d+)\nY Position[^\d]+(\d+)")

for filename in os.listdir("challenge"):
    try:
        print(filename)

        p = subprocess.Popen(
            f"exiftool challenge/{filename}",
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            shell=True,
        )
        stdout, stderr = p.communicate()
        if stderr:
            print(stderr)
            raise Exception
        cords = re.search(pattern, stdout.decode()).groups()
        cords = (int(cords[0]) * 4, int(cords[1]) * 3)
        print(cords)
        if cords[0] + 4 > collage.shape[1]:  # expand x
            expand_by = cords[0] + 4 - collage.shape[1]
            collage = np.concatenate(
                (collage, np.zeros((collage.shape[0], expand_by, 3))), axis=1
            )
        if cords[1] + 3 > collage.shape[0]:  # expand y
            expand_by = cords[1] + 3 - collage.shape[0]
            collage = np.concatenate(
                (collage, np.zeros((expand_by, collage.shape[1], 3))), axis=0
            )

        # cv.imshow("a", cv.resize(cv.imread(f"challenge/{filename}"), (4,3)))
        img = cv.imread(f"challenge/{filename}")
        if type(img) != np.ndarray:
            raise Exception
        collage[cords[1] : cords[1] + 3, cords[0] : cords[0] + 4] = cv.resize(
            img, (4, 3)
        )
        cv.imshow("result", collage)
        cv.waitKey(1)
        # cv.imshow("b", collage[cords[1]:cords[1]+3, cords[0]:cords[0]+4])
        # cv.waitKey(0)
    except Exception as e:
        # raise e
        print("error")

print(collage.shape)
cv.imwrite("collage2.png", collage)
