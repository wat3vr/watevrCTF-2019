
gcc sheap.c -o $PWD/downloads/spottify
gcc sheap_server.c -o $PWD/container/service

strip $PWD/downloads/spottify
strip $PWD/container/service

chmod +x $PWD/downloads/spottify
chmod +x $PWD/container/service
