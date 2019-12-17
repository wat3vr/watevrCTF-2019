gcc server.c -o $PWD/downloads/server
gcc client.c -o $PWD/downloads/client
gcc real_server.c -o $PWD/container/service

chmod +x $PWD/downloads/server
chmod +x $PWD/downloads/client
chmod +x $PWD/container/service

strip $PWD/downloads/server
strip $PWD/downloads/client
strip $PWD/container/service

read -p 'flag: ' flag

cp database.txt $PWD/container/
echo $flag > $PWD/container/flag.txt
