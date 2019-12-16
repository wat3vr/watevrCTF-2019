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
        with open(f"challenge/{filename}", "rb") as f:
            img = bytearray(f.read())

        img[:2] = b"\xff\xd8"  # fix start bytes
        img[-2:] = b"\xff\xd9"  # fix end bytes

        with open(f"challenge/{filename}", "wb") as f:
            f.write(img)

        if img[0x12] != 0:  # thumbnail exists
            x_res = img[0x12]
            y_res = img[0x13]
            if img[4] * 256 + img[5] != x_res * y_res * 3 + 0x10:  # wrong APP0 length
                img[4:6] = (x_res * y_res * 3 + 0x10).to_bytes(2, "big")
                with open(f"challenge/{filename}", "wb") as f:
                    f.write(img)
            pixel_count = x_res * y_res
            thumbnail_bytes = img[0x14 : 0x14 + pixel_count * 3]
            thumbnail_img = np.array(thumbnail_bytes, dtype=np.uint8).reshape(
                y_res, x_res, 3
            )
            thumbnail_img = cv.cvtColor(thumbnail_img, cv.COLOR_RGB2BGR)
        else:
            try:
                img.index(b"\xff\xda")
            except ValueError:
                index = 2
                marker_length = 0
                marker = img[index]
                while marker == 0xFF:
                    marker_length = img[index + 2] * 256 + img[index + 3]
                    index += marker_length + 2
                    marker = img[index]
                img = img[:index] + b"\xff\xda" + img[index:]
                with open(f"challenge/{filename}", "wb") as f:
                    f.write(img)

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
        img = cv.imread(f"challenge/{filename}") if not img[0x12] else thumbnail_img
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
        raise e

print(collage.shape)
cv.imwrite("collage.png", collage)
