FROM ubuntu

RUN apt update && apt upgrade -y

RUN apt install -y python3 python3-pip nginx
RUN pip3 install aiohttp aiohttp_jinja2 jinja2 aiohttp_session gunicorn itsdangerous

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf/

COPY flag.txt server.py /home/ctf/
COPY static /home/ctf/static/
COPY templates /home/ctf/templates/
COPY ctf-site /etc/nginx/sites-enabled/
RUN rm /etc/nginx/sites-enabled/default

RUN chown -R root:ctf /home/ctf/
RUN chmod -R 750 /home/ctf/

WORKDIR /home/ctf/

CMD nginx && gunicorn server:app -b 0.0.0.0:8000 --worker-class aiohttp.GunicornWebWorker -u ctf -g ctf