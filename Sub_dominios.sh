#!/bin/bash
if [ "$1" == "" ]
then
echo "Exemplo de uso ./parse.sh site.com"
else
wget $1 2>/dev/null
cat index.html | grep href | cut -d "/" -f3 | cut -d '"' -f 1 | grep -v ">" | grep -v "<" > lista
for url in $(cat lista)
do 
host $url
done | grep "has"
rm lista
rm index.html
fi