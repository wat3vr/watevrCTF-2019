import json
import base64
import pickle
import hmac
from flask import Flask, render_template, request, make_response, redirect

application = Flask(__name__)

f = open("flag.txt")
flag = f.read()
f.close()

key = b"58c93becce9a13c96778ded0edd8096d"

all_cookies = [
    {
        "name": "Standard Pickle",
        "description": "The classic pickle you know and love.",
        "price": 10,
        "image": "standard_pickle.jpg",
        "text": "Yummy standard pickle",
    },
    {
        "name": "Smörgåsgurka",
        "description": "Smörgåsgurka, great for a sandwitch!",
        "price": 100,
        "image": "smorgasgurka.jpg",
        "text": "Yummy smörgåsgurka",
    },
    {
        "name": "Flag Pickle",
        "description": "The flag Pickle you have always wanted!",
        "price": 1000,
        "image": "flag_pickle.jpg",
        "text": flag,
    },
]


@application.route("/", methods=["GET"])
def index():
    cookies = request.cookies.get("session")
    if not cookies:
        cookies = {"money": 500, "history": []}
    else:
        cookies = pickle.loads(base64.b64decode(cookies))
        digest = cookies["anti_tamper_hmac"]
        del cookies["anti_tamper_hmac"]
        h = hmac.new(key)
        h.update(str(cookies).encode())
        if not hmac.compare_digest(h.digest().hex(), digest):
            cookies = {"money": 500, "history": []}

    resp = make_response(
        render_template(
            "index.html",
            cookies=all_cookies,
            money=cookies["money"],
            history=cookies["history"],
        )
    )
    h = hmac.new(key)
    h.update(str(cookies).encode())
    cookies["anti_tamper_hmac"] = h.digest().hex()
    resp.set_cookie("session", base64.b64encode(pickle.dumps(cookies)))
    return resp


@application.route("/buy", methods=["POST"])
def buy():
    cookies = request.cookies.get("session")
    if not cookies:
        cookies = {"money": 500, "history": []}
    else:
        cookies = pickle.loads(base64.b64decode(cookies))
        digest = cookies["anti_tamper_hmac"]
        del cookies["anti_tamper_hmac"]
        h = hmac.new(key)
        h.update(str(cookies).encode())
        if not hmac.compare_digest(h.digest().hex(), digest):
            cookies = {"money": 500, "history": []}

    assert "id" in request.form
    cookie_id = int(request.form["id"])
    if all_cookies[cookie_id]["price"] <= cookies["money"]:
        cookies["money"] -= all_cookies[cookie_id]["price"]
        cookies["history"].append(all_cookies[cookie_id]["text"])

    resp = make_response(redirect("/"))
    h = hmac.new(key)
    h.update(str(cookies).encode())
    cookies["anti_tamper_hmac"] = h.digest().hex()
    resp.set_cookie("session", base64.b64encode(pickle.dumps(cookies)))
    return resp


if __name__ == "__main__":
    application.run(host="0.0.0.0", port=8000, threaded=False)
