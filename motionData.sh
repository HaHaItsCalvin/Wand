#!/bin/sh

echo "Motion"
read motion
echo "start file #"
read i
echo "End file #"
read end


while [ $i -lt $(($end+1)) ]
do
cat ~/Wand/"$motion"/Motion_data/peaks/sorted/"$motion"_sorted_zpeaks_"$i"
wc -l < ~/Wand/"$motion"/Motion_data/peaks/sorted/"$motion"_sorted_zpeaks_"$i"

i=$(($i+1))

done
