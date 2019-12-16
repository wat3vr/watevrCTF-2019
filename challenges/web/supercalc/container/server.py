import time
import traceback
import sys
from flask import Flask, render_template, session, request, render_template_string
from evalfilter import validate

app = Flask(__name__)
app.secret_key = "cded826a1e89925035cc05f0907855f7"


def format_code(code):
    if "#" in code:
        code = code[: code.index("#")]

    return code


@app.route("/", methods=["GET", "POST"])
def index():
    if not session.get("history"):
        session["history"] = []

    if request.method == "POST":
        result = validate(request.form["code"])
        if not result[0]:
            return result[1]

        session["history"].append({"code": result[1]})
        if len(session["history"]) > 5:
            session["history"] = session["history"][1:]
        session.modified = True

        try:
            eval(request.form["code"])
        except:
            error = traceback.format_exc(limit=0)[35:]
            session["history"][-1]["error"] = render_template_string(
                f'Traceback (most recent call last):\n  File "somewhere", line something, in something\n    result = {request.form["code"]}\n{error}'
            )

    history = []
    for calculation in session["history"]:
        history.append({**calculation})
        if not calculation.get("error"):
            history[-1]["result"] = eval(calculation["code"])

    return render_template("index.html", history=list(reversed(history)))


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
