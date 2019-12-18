read -p "Flag: " FLAG

rm -rf downloads
rm -rf container/service

mkdir downloads

sed -e "s/FLAG_HERE/$FLAG/" game.c > rendered.c

gcc -fno-stack-protector -no-pie rendered.c -o container/service
# cp a.out container/service
python3 redact_flag.py container/service downloads/M-x-5x5
