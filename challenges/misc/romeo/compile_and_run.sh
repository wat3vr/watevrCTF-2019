#!/bin/bash

./spl/spl2c < $1 > out.c
gcc -O2 -Wall -Wno-unused -I./spl/spl/include -c out.c
gcc -O2 -Wall -Wno-unused out.o -L./spl/spl/lib -lspl -o out -lm
./out
rm out.c
rm out.o
rm out
