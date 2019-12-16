import os
from PIL import Image, ImageDraw, ImageFont
import cv2.cv2 as cv
import numpy as np
import random
import shutil
import subprocess
import inspect
import zipfile

flag_prefix = "watevr{collages_are_nice_"
flag_suffix = "}"
collage_pixel_size = (4, 3)
collage_pixel_height = 14
brightness_tolerance = 100
font = ImageFont.load_default()

random.seed(os.urandom(8))
photos = {i: [] for i in range(256)}


def read_img(filename):
    with open(f"challenge/{filename}.jpg", "rb") as f:
        return bytearray(f.read())


def write_img(filename, data):
    with open(f"challenge/{filename}.jpg", "wb") as f:
        f.write(data)


class corrupters:
    @staticmethod
    def fake_corrupter(filename):
        pass

    @staticmethod
    def start_bytes(filename):
        img = read_img(filename)
        img[1] = 0
        write_img(filename, img)

    @staticmethod
    def end_bytes(filename):
        img = read_img(filename)
        img[-2] = 0
        write_img(filename, img)

    @staticmethod
    def img_in_thumbnail(filename):
        img = read_img(filename)
        cvimg = cv.imdecode(np.frombuffer(img, np.uint8), cv.IMREAD_COLOR)
        cvimg = cv.cvtColor(cvimg, cv.COLOR_BGR2RGB)

        # corrupting huffman tables
        index = 2
        marker = 0
        while marker != 0xDA:
            marker = img[index + 1]
            index += 2
            marker_length = img[index] * 256 + img[index + 1]

            if marker == 0xC4:  # huffman table
                img[index + 2 : index + marker_length] = bytearray([255]) * (
                    marker_length - 2
                )

            index += marker_length

        # moving img to thumbnail
        res_multiplier = random.randint(1, 25)
        resolution = (4 * res_multiplier, 3 * res_multiplier)
        cvimg = cv.resize(cvimg, resolution)
        img = (
            img[:0x4]
            + (resolution[0] * resolution[1] * 3 + 0x10).to_bytes(2, "big")
            + img[0x6:0x12]
            + resolution[0].to_bytes(1, "big")
            + resolution[1].to_bytes(1, "big")
            + bytearray(cvimg.flatten())
            + img[0x14:]
        )

        write_img(filename, img)

    @staticmethod
    def img_in_thumbnail_and_wrong_JFIF_APP0_length(filename):
        corrupters.img_in_thumbnail(filename)
        img = read_img(filename)
        APP0_length = img[4] * 256 + img[5]
        img[4:6] = random.randint(APP0_length + 1, APP0_length * 2).to_bytes(2, "big")
        write_img(filename, img)

    @staticmethod
    def missing_SOS_marker(filename):
        img = read_img(filename)
        index = img.index(b"\xff\xda")
        img = img[:index] + img[index + 2 :]
        write_img(filename, img)


def create_img(text, width=None):
    img = Image.new("L", (1, 1), (255))
    draw = ImageDraw.Draw(img)
    dimensions = draw.textsize(text, font=font)
    if width:
        dimensions = (width, dimensions[1])
    img = img.resize((dimensions[0], collage_pixel_height))
    draw = ImageDraw.Draw(img)
    draw.text(
        (0, (collage_pixel_height - dimensions[1]) // 2), text, font=font, fill=(0)
    )
    img = img.resize((img.size[0] * 4, img.size[1] * 3))
    return np.array(img)


def get_photo_by_brightness(brightness):
    global photo_index
    brightnesses = list(
        [i for i in range(256) if abs(i - brightness) <= brightness_tolerance]
    )
    random.shuffle(brightnesses)
    for i in brightnesses:
        if photos[i]:
            return photos[i].pop(0)

    for filename in photo_filenames[photo_index:]:
        photo_index += 1
        img = cv.imread(f"images/{filename}")
        photo_brightness = round(np.mean(cv.cvtColor(img, cv.COLOR_BGR2GRAY)))
        if photo_brightness in brightnesses:
            return filename
        photos[photo_brightness].append(filename)

    print("not enough images")
    exit(1)


corrupter_functions = [
    i[1] for i in inspect.getmembers(corrupters, predicate=inspect.isfunction)
]
random.shuffle(corrupter_functions)

flag_img = np.ones((collage_pixel_height * collage_pixel_size[1], 8)) * 255

flag_img = np.concatenate((flag_img, create_img(flag_prefix)), axis=1)

flag_img = np.concatenate(
    (flag_img, np.ones((collage_pixel_height * collage_pixel_size[1], 4)) * 255), axis=1
)

corrupters_x = []
randstring = ""
for func in corrupter_functions:
    x = flag_img.shape[1]
    rnd = os.urandom(2).hex()
    flag_img = np.concatenate((flag_img, create_img(rnd, 24)), axis=1)
    corrupters_x.append((x, flag_img.shape[1]))
    randstring += rnd

flag_img = np.concatenate(
    (flag_img, np.ones((collage_pixel_height * collage_pixel_size[1], 4)) * 255), axis=1
)

flag_img = np.concatenate((flag_img, create_img(flag_suffix)), axis=1)

shutil.rmtree("challenge")
os.mkdir("challenge")

photo_filenames = os.listdir("images")
photo_index = 0
image_count = len(range(0, flag_img.shape[0], collage_pixel_size[1])) * len(
    range(0, flag_img.shape[1], collage_pixel_size[0])
)
count = 0
processes = []
filenames = []

for y in range(0, flag_img.shape[0], collage_pixel_size[1]):
    for x in range(0, flag_img.shape[1], collage_pixel_size[0]):
        collage_pixel = flag_img[
            y : y + collage_pixel_size[1], x : x + collage_pixel_size[0]
        ]

        average = round(np.mean(collage_pixel))
        filename = get_photo_by_brightness(average)
        img = cv.imread(f"images/{filename}")
        img = cv.resize(img, (100, 75))
        filename = os.urandom(8).hex()
        filenames.append(filename)
        cv.imwrite(f"challenge/{filename}.jpg", img)
        processes.append(
            (
                subprocess.Popen(
                    f"exiftool -XPosition={int(x/4)} -YPosition={int(y/3)} -ResolutionUnit= -XResolution= -YCbCrPositioning= -YResolution= challenge/{filename}.jpg > /dev/null",
                    shell=True,
                ),
                x,
                filename,
            )
        )

        count += 1
        print(f"{int(count/image_count*1000)/10}%")

print("running corrupters...")

for process, x, filename in processes:
    process.wait()
    for i, corrupter_x in enumerate(corrupters_x):
        if corrupter_x[0] <= x < corrupter_x[1]:
            corrupter_functions[i](filename)
            break

for filename in filenames:
    os.remove(f"challenge/{filename}.jpg_original")

archive = zipfile.ZipFile("photos.zip", "w", zipfile.ZIP_DEFLATED)
for filename in os.listdir("challenge"):
    archive.write(f"challenge/{filename}", filename)
archive.close()

os.system("touch -t 133701010000 challenge/*") # Real bruh moment right here, obfuscating creation time after the archive is created

print(f"{flag_prefix}{randstring}{flag_suffix}")
