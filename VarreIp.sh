#!/bin/bash
if [ "$1" == "" ]
then
echo "Exemplo de uso ./prog.sh 192.168.0"
else
for host in {1..254}
do
ping -c 1 $1.$host | grep "64 bytes" | cut -d " " -f 4 | cut -d ":" -f 1
done
fi
