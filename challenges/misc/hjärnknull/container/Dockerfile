FROM ubuntu

RUN apt update && apt upgrade -y

RUN apt install -y xinetd
RUN yes Y | apt install build-essential

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf/
ENV LANG C.UTF-8

RUN apt install -y python3

COPY service /home/ctf/
COPY challenge_file.txt /home/ctf/challenge_file.txt
COPY flag.txt /home/ctf/

COPY xinetd_config /etc/xinetd.d/

RUN chown -R root:ctf /home/ctf/
RUN chmod -R 750 /home/ctf/

EXPOSE 50000

CMD service xinetd restart && /bin/sleep infinity
