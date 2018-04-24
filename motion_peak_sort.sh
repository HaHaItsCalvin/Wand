#!/bin/bash

gcc -o correct_bubble_sort_norm correct_bubble_sort_norm.c

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
./correct_bubble_sort_norm ~/Wand/"$motion"/Motion_data/peaks/"$motion"_xpeaks_$i.csv ~/Wand/"$motion"/Motion_data/peaks/sorted/"$motion"_sorted_xpeaks_$i.csv ~/Wand/"$motion"/Motion_data/peaks/"$motion"_zpeaks_$i.csv ~/Wand/"$motion"/Motion_data/peaks/sorted/"$motion"_sorted_zpeaks_$i.csv


i=$(($i+1))
done
