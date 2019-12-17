read -p 'flag: ' flag
gcc rsa_shell.c -o $PWD/downloads/watshell
chmod +x $PWD/downloads/watshell
strip $PWD/downloads/watshell
cp $PWD/downloads/watshell $PWD/container/service
echo $flag > $PWD/container/flag.txt
