read -p 'flag: ' flag

rm $PWD/container/service
rm $PWD/downloads/betstar5000
gcc -m32 -g -Wl,-z,norelro kareoke.c -o $PWD/container/service
strip $PWD/container/service
cp $PWD/container/service $PWD/downloads/betstar5000
cp $PWD/libc-2.27.so $PWD/downloads

echo $flag > $PWD/container/flag.txt
