#!/bin/bash

gcc -o bubble_sort_norm_Edited bubble_sort_norm_Edited.c

echo "What's the motion? all lowercase ex: patronus, shrinking"
read motion
echo "How many files?"
read end

if [ ! -d "~/Wand/"$motion"/Motion_Data/peaks/sorted" ]; then
mkdir ~/Wand/"$motion"/Motion_data/peaks/sorted
fi

i=1
while [ $i -lt $(($end+1)) ]
do
./bubble_sort_norm_Edited ~/Wand/"$motion"/Motion_data/peaks/"$motion"_xpeaks_$i ~/Wand/"$motion"/Motion_data/peaks/sorted/"$motion"_sorted_xpeaks_$i ~/Wand/"$motion"/Motion_data/peaks/"$motion"_zpeaks_$i ~/Wand/"$motion"/Motion_data/peaks/sorted/"$motion"_sorted_zpeaks_$i


i=$(($i+1))
done
