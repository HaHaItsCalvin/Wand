#!/bin/sh
#This file prints out all the normalized & sorted Xpeak values &Ypeak values 
#followed by the raw diagonal X&Y peak datas

i=1
echo "enter end file #"
read end
while [ $i -lt $(($end+1)) ]
do
echo "Peaks Number " $i
cat ~/Wand/patronus_xsortedpeaks_$i

echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
cat ~/Wand/patronus_ysortedpeaks_$i
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"


i=$(($i+1))
done
