import json
import base64
import asyncio
import aiohttp
import aiohttp_jinja2
import jinja2
import itsdangerous
from aiohttp_session import setup, get_session
from aiohttp_session.cookie_storage import AbstractStorage, Session

routes = aiohttp.web.RouteTableDef()
app = aiohttp.web.Application()
aiohttp_jinja2.setup(app, loader=jinja2.FileSystemLoader("./templates"))

f = open("flag.txt")
flag = f.read()
f.close()

redirects = 50

paths = [
    [i for i in range(1, redirects + 1)],
    [
        46,
        44,
        49,
        12,
        19,
        42,
        32,
        8,
        43,
        27,
        50,
        14,
        48,
        5,
        3,
        9,
        28,
        6,
        36,
        7,
        29,
        2,
        20,
        17,
        31,
        45,
        16,
        35,
        4,
        13,
        26,
        11,
        47,
        22,
        37,
        10,
        23,
        38,
        18,
        40,
        24,
        33,
        34,
        39,
        41,
        1,
        25,
        15,
        30,
        21,
    ],
]


@routes.get("/")
@aiohttp_jinja2.template("index.html")
async def index(request):
    session = await get_session(request)
    session["steps"] = []
    return {
        "text": "The path to the temple will be long, will you make it?",
        "image": "static/jungle.jpg",
        "link": True,
    }


@routes.get("/path/{step}")
async def path(request):
    try:
        step = int(request.match_info["step"])
    except Exception:
        raise aiohttp.web.HTTPNotFound()
    session = await get_session(request)
    if session.get("steps") == None:
        session["steps"] = []
    session["steps"].append(step)
    session.changed()

    safelen = min(len(session["steps"]), 50)

    if step in [paths[0][safelen - 1], paths[1][safelen - 1]]:
        await asyncio.sleep(0.5)

    if len(session["steps"]) >= redirects:
        if session["steps"] == paths[0]:
            raise aiohttp.web.HTTPFound("/temple")
        elif session["steps"] == paths[1]:
            raise aiohttp.web.HTTPFound("/flag")
        raise aiohttp.web.HTTPFound("/lost")

    raise aiohttp.web.HTTPFound("/path/%s" % (step + 1))


@routes.get("/temple")
@aiohttp_jinja2.template("index.html")
async def temple(request):
    session = await get_session(request)
    if session["steps"] == paths[0]:
        session["steps"] = []
        return {"text": "You found the temple!", "image": "static/temple.jpg"}
    raise aiohttp.web.HTTPFound("/lost")


@routes.get("/flag")
@aiohttp_jinja2.template("index.html")
async def flag2(request):
    session = await get_session(request)
    if session["steps"] == paths[1]:
        session["steps"] = []
        return {
            "text": "You exited the jungle and stumbled upon a flag!<br><br>%s" % flag,
            "image": "static/flag.jpg",
        }
    raise aiohttp.web.HTTPNotFound()


@routes.get("/lost")
@aiohttp_jinja2.template("index.html")
async def lost(request):
    session = await get_session(request)
    session["steps"] = []
    return {
        "text": "You got lost and found a tiger! you better run back and start over.",
        "image": "static/lost.jpg",
    }


class CookieStorage(AbstractStorage):
    def __init__(
        self,
        secret_key,
        *,
        cookie_name="AIOHTTP_SESSION",
        domain=None,
        max_age=None,
        path="/",
        secure=None,
        httponly=True,
        encoder=json.dumps,
        decoder=json.loads
    ):
        super().__init__(
            cookie_name=cookie_name,
            domain=domain,
            max_age=max_age,
            path=path,
            secure=secure,
            httponly=httponly,
            encoder=encoder,
            decoder=decoder,
        )

        if isinstance(secret_key, str):
            pass
        elif isinstance(secret_key, (bytes, bytearray)):
            secret_key = base64.urlsafe_b64encode(secret_key)
        self._s = itsdangerous.Signer(secret_key)

    async def load_session(self, request):
        cookie = self.load_cookie(request)
        if cookie is None:
            return Session(None, data=None, new=True, max_age=self.max_age)
        else:
            try:
                data = self._decoder(self._s.unsign(base64.b64decode(cookie)))
                return Session(None, data=data, new=False, max_age=self.max_age)
            except (itsdangerous.BadSignature, base64.binascii.Error):
                print("session failed")
                return Session(None, data=None, new=True, max_age=self.max_age)

    async def save_session(self, request, response, session):
        if session.empty:
            return self.save_cookie(response, "", max_age=session.max_age)

        cookie_data = self._encoder(self._get_session_data(session)).encode("utf-8")
        self.save_cookie(
            response,
            base64.b64encode(self._s.sign(cookie_data)).decode("utf-8"),
            max_age=session.max_age,
        )


app.router.add_static("/static", "static")
setup(app, CookieStorage(b"9UfJoKAdiU9HnmiNzvII72SFb@&Q5&&o"))
app.add_routes(routes)

if __name__ == "__main__":
    aiohttp.web.run_app(app, port=50000)
