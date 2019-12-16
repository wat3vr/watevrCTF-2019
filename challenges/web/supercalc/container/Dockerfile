FROM ubuntu

RUN apt update && apt upgrade -y

RUN apt install -y python3 python3-pip nginx
RUN pip3 install flask gunicorn

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf/

COPY flag.txt server.py evalfilter.py /home/ctf/
COPY templates /home/ctf/templates/
COPY ctf-site /etc/nginx/sites-enabled/
RUN rm /etc/nginx/sites-enabled/default

RUN chown -R root:ctf /home/ctf/
RUN chmod -R 750 /home/ctf/

WORKDIR /home/ctf/

CMD nginx && gunicorn server:app -u ctf -g ctf -w 6 -t 3 --graceful-timeout 1 -b 0.0.0.0:8000