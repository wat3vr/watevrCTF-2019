read -p 'flag: ' flag

rm $PWD/container/service
rm $PWD/downloads/wat-sql

gcc -lpthread -no-pie -pthread srce.c -o $PWD/downloads/wat-sql
gcc -lpthread -no-pie -pthread srce.c -o $PWD/container/service

strip $PWD/downloads/wat-sql
strip $PWD/container/service

echo $flag > $PWD/container/flag.txt

cp database.txt $PWD/container/

chmod 777 $PWD/container/flag.txt
chmod 777 $PWD/container/database.txt
