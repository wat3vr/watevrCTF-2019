from flask import Flask, request, escape
import os

app = Flask("")

@app.route("/")
def index():
    return get("index.html")

@app.route("/<path:path>")
def get(path):
    print("Getting", path)
    if ".." in path:
        return ""

    if "logs" in path or ".gti" in path:
        return "Please do not access the .git-folder"

    if "index" in path:
        path = "index.html"

    if os.path.isfile(path):
        return open(path, "rb").read()

    if os.path.isdir(path):
        return get("folder.html")

    return "404 not found"


if __name__ == "__main__":
    app.run("0.0.0.0", "8000")