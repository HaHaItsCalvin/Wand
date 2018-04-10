#!/bin/sh

#Takes two input values and appends them to SimpleTrainingData.txt
#
i=1 

echo "Which file# to stop with"
read end

while [ $i -lt $(($end+1)) ]
do
echo "$i"
mv ~/Wand/patronus_xsortedpeaks_$i ~/Wand/Patronus
mv ~/Wand/patronus_ysortedpeaks_$i ~/Wand/Patronus
#echo "input desired data points"
#read input_variable
i=$(($i+1))
done

