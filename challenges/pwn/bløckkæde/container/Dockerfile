FROM ubuntu

RUN apt update && apt upgrade -y

RUN apt install -y xinetd
RUN yes Y | apt install build-essential

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf/
RUN FLAG="watevr{xd}"
COPY service /home/ctf/
COPY xinetd_config /etc/xinetd.d/

RUN chown -R root:ctf /home/ctf/
RUN chmod -R 750 /home/ctf/

EXPOSE 50000

CMD service xinetd restart && /bin/sleep infinity
