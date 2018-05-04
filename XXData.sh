#!/bin/sh

echo "Motion"
read motion
echo "start file #"
read i
echo "End file #"
read end


while [ $i -lt $(($end+1)) ]
do
cat ~/Wand/"$motion"/Xcorr_data/peaks/autocorr_peaks/"$motion"_xxpeaks_"$i".csv
wc -l < ~/Wand/"$motion"/Xcorr_data/peaks/autocorr_peaks/"$motion"_xxpeaks_"$i".csv

i=$(($i+1))

done
