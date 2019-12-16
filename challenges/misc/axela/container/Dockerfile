FROM ubuntu

RUN apt update && apt upgrade -y

RUN apt install -y python3 python3-pip
RUN pip3 install discord aiohttp

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf/

COPY bot.py /home/ctf/bot.py

RUN chown -R root:ctf /home/ctf/
RUN chmod -R 750 /home/ctf/

USER ctf

CMD python3 /home/ctf/bot.py