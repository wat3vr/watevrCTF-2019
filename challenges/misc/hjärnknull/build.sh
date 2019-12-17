read -p "flag: " flag
cp hjärnknull.py container/service

cp clarification downloads/clarification
cp hjärnknull.py downloads/hjärnknull.py

echo $flag > container/flag.txt

echo "2 5 15:75\n2 44 4578:201432\n2 154545 1:154545\n0 5 9:14\n" > container/challenge_file.txt