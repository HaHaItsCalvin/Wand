#!/bin/sh

#Takes two input values and appends them to SimpleTrainingData.txt
#
i=1 
echo "What motion is it? all lowercase!!  EX: patronus, disarm"
read file
echo "Which file# to stop with"
read end


if [ ! -d "~/Wand/"$file"/Motion_data/peaks" ]; then
mkdir ~/Wand/"$file"/Motion_data/peaks
fi

while [ $i -lt $(($end+1)) ]
do
echo "$i"
#mv ~/Wand/FeatureExtraction/disarm_motion_$i ~/Wand/Disarm/Motion_data
mv ~/Wand/FeatureExtraction/"$file"_xpeaks_$i ~/Wand/"$file"/Motion_data/peaks
mv ~/Wand/FeatureExtraction/"$file"_ypeaks_$i ~/Wand/"$file"/Motion_data/peaks
mv ~/Wand/FeatureExtraction/"$file"_zpeaks_$i ~/Wand/"$file"/Motion_data/peaks
#echo "input desired data points"
#read input_variable
i=$(($i+1))
done

