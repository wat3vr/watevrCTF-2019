from flask import Flask, request, escape
import backend

app = Flask("LibraryOfBabel")

@app.route("/")
def index():
    return f"""
<html>
    <head></head>

    <body>
        <h1> Welcome to the Library of Babel! </h1>

        <a href="view?page=0">Browse the library</a>
        <br/>
        <a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ">Search a for book</a>
        <br/>
        <a href="source">View the source</a>
    </body>
</html>
"""

@app.route("/source")
def source_index():
    return f"""
<html>
    <head></head>

    <body>
        <h3> Files: </h3>

        <pre>
<a href="source/web.py">web.py</a>

<a href="source/backend.py">book_generator.py</a>
        </pre>
    </body>
</html>
"""

@app.route("/source/web.py")
def source_web():
    return f"""
<html>
    <head></head>
    <body>
        <pre>{escape(open("web.py").read())}</pre>
    </body>
</html>
"""

@app.route("/source/backend.py")
def source_backend():
    return f"""
<html>
    <head></head>
    <body>
        <pre>{escape(open("backend.py").read())}</pre>
    </body>
</html>
"""

@app.route("/view")
def browse():
    n = int(request.args.get("page") or "0")
    n = max(0, min(n, backend.m))

    offset = int(request.args.get("offset") or "0")
    offset = max(0, min(offset, 100))

    page_1 = ""
    for i in range(100 * n + offset, 100 * (n + 1) + offset):
        page_1 += backend.n2st(backend.f(i)) + " "

    page_2 = ""
    for i in range(100 * (n+1) + offset, 100 * (n+2) + offset):
        page_2 += backend.n2st(backend.f(i)) + " "

    return f"""
<html>
    <head>
<meta name="google" content="notranslate">
<style>
.book {{
    border: 1px solid black;
    border-radius: 5px;
    padding: 10px;
    background: #eb9;
    position: absolute;
    -webkit-box-shadow: 0px 10px 13px 0px rgba(0,0,0,0.75);
    -moz-box-shadow: 0px 10px 13px 0px rgba(0,0,0,0.75);
    box-shadow: 0px 10px 13px 0px rgba(0,0,0,0.75);
}}

.page {{
    width: 350px;
    border: 1px solid black;
    border-radius: 2px;
    background: white;
    padding: 20px;
    float: left;
    margin: 10px;
}}

.pagenr {{
    text-align: center;
    width: 100%;
}}

</style>
    </head>
    <body>
        <div class="book">
            <div class="page">
                {page_1}
                <br/>
                <br/>
                <div class="pagenr">{n}</div>
                <a href="view?page={n-2}"> &larr; </a>
            </div>
            <div class="page">
                {page_2}
                <br/>
                <br/>
                <div class="pagenr">{n+1}</div>
                <div style="text-align: right; width: 100%">
                    <a href="view?page={n+2}" > &rarr; </a>
                </div>
            </div>
        </div>
    </body>
</html>
"""

if __name__ == "__main__":
    app.run("0.0.0.0", "8000")
