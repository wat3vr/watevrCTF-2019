read -p 'flag: ' flag

rm $PWD/container/service
rm $PWD/downloads/kamikaze2

gcc kamikaze2.c -no-pie -fno-stack-protector -m32 -Wl,-Ttext=0x08420620 -o $PWD/container/service
gcc kamikaze2.c -no-pie -fno-stack-protector -m32 -Wl,-Ttext=0x08420620 -o $PWD/downloads/kamikaze2

strip $PWD/container/service
strip $PWD/downloads/kamikaze2

cp $PWD/libc-2.27.so $PWD/downloads
echo $flag > $PWD/container/flag.txt
