read -p 'flag: ' flag
rm $PWD/container/service
rm $PWD/downloads/kamikaze
gcc kamikaze.c -o $PWD/container/service -no-pie -fno-stack-protector
gcc kamikaze.c -o $PWD/downloads/kamikaze -no-pie -fno-stack-protector
echo $flag > $PWD/container/flag.txt
