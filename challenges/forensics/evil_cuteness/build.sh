#!/bin/bash
read flag
echo $flag > abc
cp kitty.jpg downloads/kitty.jpg
zip secret.zip abc
cat secret.zip >> downloads/kitty.jpg
