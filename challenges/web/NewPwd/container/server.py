import time
import random
import os
import io
import json
import base64
from flask import Flask, render_template, redirect, session, abort, send_file, request
from PIL import Image, ImageDraw, ImageFont

application = Flask(__name__)
application.secret_key = "#7YtVa1NTRP18J8uuxshr%Mj95xV#Dp4"

f = open("flag.txt")
flag = f.read()
f.close()

font = ImageFont.truetype("font/Roboto-Regular.ttf", 40)
captcha_overlays = [
    11070196256014366476,
]

alphabet = "ABCDEFGHIJKLMNPQRSTUVWXYZ2345689"
admin_alphabet = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
sessions = {}


def generate_overlay(seed):
    random.seed(seed)
    img = Image.new("RGBA", (200, 50))
    draw = ImageDraw.Draw(img)
    pixels = []
    for x in range(200):
        for y in range(50):
            if random.randint(1, 100) < 60:
                pixels.append((x, y))
    draw.point(pixels, fill=(0, 0, 0, 255))
    for _ in range(5):
        draw.line(
            [(random.randint(0, 199), random.randint(0, 49)) for _ in range(2)],
            fill=(0, 0, 0, 255),
            width=3,
        )
    return img


captcha_overlays = [generate_overlay(seed) for seed in captcha_overlays]
letter_offsets = {
    char: (random.randint(-5, 5), random.randint(-5, 5), random.randint(-25, 25))
    for char in alphabet
}


def generate_captcha(seed=None):
    if seed == None:
        seed = os.urandom(8)

    random.seed(seed)
    captcha_text = ""

    img = Image.new("RGBA", (200, 50), (255, 255, 255, 255))
    draw = ImageDraw.Draw(img)

    for i in range(5):
        char = random.choice(alphabet)
        captcha_text += char
        char_img = Image.new("RGBA", (40, 50), (255, 255, 255, 0))
        char_draw = ImageDraw.Draw(char_img)
        char_draw.text(
            (
                (40 - draw.textsize(char, font=font)[0]) // 2 + letter_offsets[char][0],
                letter_offsets[char][1],
            ),
            char,
            fill=(0, 0, 0, 255),
            font=font,
        )
        char_img = char_img.rotate(letter_offsets[char][2], Image.BICUBIC)
        char_img = char_img.point(lambda p: (p > 128) * 255)
        img.alpha_composite(char_img, (i * 40, 0))

    captcha_type = random.randint(0, len(captcha_overlays) - 1)
    img.alpha_composite(captcha_overlays[captcha_type])
    img = img.convert("RGB")

    file = io.BytesIO()
    img.save(file, format="png")
    file.seek(0)

    return file, None, captcha_type, captcha_text


def assert_session():
    if session.get("id") == None or session["id"] not in sessions:
        session["id"] = os.urandom(8).hex()
        sessions[session["id"]] = {
            "admin_pass": "keep going"
            + "".join([random.choice(admin_alphabet) for _ in range(64)]),
            "captcha_seed": None,
            "captcha_solution": None,
            "locked": False,
        }


def new_captcha():
    session.modified = True
    sessions[session["id"]]["captcha_seed"] = os.urandom(8)
    captcha = generate_captcha(sessions[session["id"]]["captcha_seed"])
    sessions[session["id"]]["captcha_solution"] = captcha[3]
    session["captcha_type"] = captcha[2]
    if application.debug:
        session["solution"] = captcha[3]
    return captcha


@application.route("/")
def index():
    return render_template("index.html")


@application.route("/captcha.png")
def get_captcha2():
    assert_session()
    if not sessions[session["id"]]["captcha_seed"]:
        captcha = new_captcha()
    else:
        captcha = generate_captcha(sessions[session["id"]]["captcha_seed"])

    return send_file(captcha[0], mimetype="image/png")


@application.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "GET":
        return render_template("login.html", random=random.randint(0, 2 ** 64))

    assert_session()
    session.modified = True
    if sessions[session["id"]]["locked"]:
        return render_template(
            "login.html",
            random=random.randint(0, 2 ** 64),
            error="Due to our zero tolerance policy for invalid captchas, log-in has been disabled from this device.",
        )

    if sessions[session["id"]]["captcha_solution"] == request.form["captcha"].upper():
        new_captcha()
        if request.form["username"] != "admin":
            return render_template(
                "login.html", random=random.randint(0, 2 ** 64), error="Unknown user"
            )

        admin_pass = sessions[session["id"]]["admin_pass"]
        if request.form["password"] == admin_pass:
            return flag

        for i, chars in enumerate(zip(request.form["password"], admin_pass)):
            if chars[0] != chars[1]:
                message = "char missmatch at pos %s" % i
                break
        else:
            message = "unknown error"

        return render_template(
            "login.html",
            random=random.randint(0, 2 ** 64),
            error="Incorrect password",
            fake_debug=message,
        )

    else:
        sessions[session["id"]]["locked"] = True
        return render_template(
            "login.html",
            random=random.randint(0, 2 ** 64),
            error="Due to our zero tolerance policy for invalid captchas, log-in has been disabled from this device.",
        )


if __name__ == "__main__":
    application.run(host="0.0.0.0", port=8000, threaded=False)
