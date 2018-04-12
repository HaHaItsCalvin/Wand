#!/bin/sh

#Takes two input values and appends them to SimpleTrainingData.txt
#
i=1 

echo "Which file# to stop with"
read end

while [ $i -lt $(($end+1)) ]
do
echo "$i"
mv ~/FeatureExtraction/disarm_motion_$i ~/Wand/Disarm/Motion_data
mv ~/FeatureExtraction/disarm_xpeaks_$i ~/Wand/Disarm/Motion_data/peaks
mv ~/FeatureExtraction/disarm_ypeaks_$i ~/Wand/Disarm/Motion_data/peaks
#echo "input desired data points"
#read input_variable
i=$(($i+1))
done

