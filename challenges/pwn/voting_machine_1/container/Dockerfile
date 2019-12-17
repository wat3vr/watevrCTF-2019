FROM ubuntu

RUN apt update && apt upgrade -y

RUN apt install -y xinetd

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf/

COPY service /home/ctf/
COPY flag.txt /home/ctf/
COPY xinetd_config /etc/xinetd.d/

RUN chown -R root:ctf /home/ctf/
RUN chmod -R 750 /home/ctf/

EXPOSE 50000

CMD service xinetd restart && /bin/sleep infinity
