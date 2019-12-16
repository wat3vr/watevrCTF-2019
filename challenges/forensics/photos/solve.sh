read flag
if [ "watevr{collages_are_nice_8037155e0527f906d7ae4720}" != "$flag" ]
then
    exit 1
fi
echo "ef8a81a47b21c4d4788888e6105faaaa  photos.zip" | md5sum -c
