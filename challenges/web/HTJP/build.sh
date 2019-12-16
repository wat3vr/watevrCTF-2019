read flag
if [ ${#flag} != 36 ]
then
    echo "Flag must be 36 chars long"
    exit 1
fi
echo $flag > container/flag.txt