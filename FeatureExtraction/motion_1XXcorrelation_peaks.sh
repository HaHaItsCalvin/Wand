#!/bin/sh

#
#Copy the waveform peak info and threshold and save it to the aquamente_xpeaks & ypeaks files
#

echo "Enter Motion"
read motion
echo "Enter # of Peaks to calculate"
read end
echo "Enter Xthresh"
read X_thresh
echo "Enter Ythresh"
read Y_thresh
echo "$end $X_thresh $Y_thresh"

i=1

while [ $i -lt $(($end+1)) ]
do

sh find_1ZZ_peaks.sh ~/Wand/"$motion"/Xcorr_data/"$motion"_xcorr_$i $X_thresh $Y_thresh 
cp waveform_peaks_output_x.csv ~/Wand/"$motion"/Xcorr_data/peaks/autocorr_peaks/"$motion"_xxpeaks_"$i".csv
#cp waveform_peaks_output_y.csv ~/Wand/shrinking/Xcorr_data/peaks/shrinking_zzpeaks_$peak_number.csv



#echo "input desired data points"
#read input_variable

i=$(($i+1))

done

