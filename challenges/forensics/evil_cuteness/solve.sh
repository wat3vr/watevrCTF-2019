#!/bin/bash
set -e
read flag
rm -rf env
mkdir env
cd env
cp ../downloads/kitty.jpg .
binwalk kitty.jpg -e
found_flag=$(cat _kitty.jpg.extracted/abc)
echo $found_flag
if [ "$found_flag" == "$flag" ]
then
    exit 0
else
    exit 1
fi
