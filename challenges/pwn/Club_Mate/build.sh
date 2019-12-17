rm $PWD/container/service
rm $PWD/downloads/Club_Mate

gcc vending-machine.c -o $PWD/container/service
gcc Club_Mate.c -o $PWD/downloads/Club_Mate

strip $PWD/container/service
strip $PWD/downloads/Club_Mate
