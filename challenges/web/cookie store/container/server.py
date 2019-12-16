import json
import base64
from flask import Flask, render_template, request, make_response, redirect
from PIL import Image, ImageDraw, ImageFont

application = Flask(__name__)

f = open("flag.txt")
flag = f.read()
f.close()

all_cookies = [
    {
        "name": "Chocolate Chip Cookie",
        "description": "The classic chocolate chip cookie you know and love.",
        "price": 1,
        "image": "chip_cookie.jpg",
        "text": "Yummy chocolate chip cookie",
    },
    {
        "name": "Pepparkaka",
        "description": "Some Pepparkakor to get you into the christmas spirit.",
        "price": 10,
        "image": "pepparkaka.jpg",
        "text": "Yummy pepparkaka",
    },
    {
        "name": "Flag Cookie",
        "description": "The flag cookie you have always wanted!",
        "price": 100,
        "image": "flag_cookie.jpg",
        "text": flag,
    },
]


@application.route("/", methods=["GET"])
def index():
    cookies = request.cookies.get("session")
    if not cookies:
        cookies = {"money": 50, "history": []}
    else:
        cookies = json.loads(base64.b64decode(cookies))

    resp = make_response(
        render_template(
            "index.html",
            cookies=all_cookies,
            money=cookies["money"],
            history=cookies["history"],
        )
    )
    resp.set_cookie("session", base64.b64encode(json.dumps(cookies).encode()))
    return resp


@application.route("/buy", methods=["POST"])
def buy():
    cookies = request.cookies.get("session")
    if not cookies:
        cookies = {"money": 50, "history": []}
    else:
        cookies = json.loads(base64.b64decode(cookies))

    print(request.form)
    assert "id" in request.form
    cookie_id = int(request.form["id"])
    if all_cookies[cookie_id]["price"] <= cookies["money"]:
        cookies["money"] -= all_cookies[cookie_id]["price"]
        cookies["history"].append(all_cookies[cookie_id]["text"])

    resp = make_response(redirect("/"))
    resp.set_cookie("session", base64.b64encode(json.dumps(cookies).encode()))
    return resp


if __name__ == "__main__":
    application.run(host="0.0.0.0", port=8000, threaded=False)
