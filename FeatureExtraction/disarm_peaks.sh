#!/bin/sh

#
#Copy the waveform peak info and threshold and save it to the patronus_xpeaks & ypeaks files
#

echo "Enter Peak$"
read peak_number 
echo "Enter Xthresh"
read X_thresh
echo "Enter Ythresh"
read Y_thresh
echo "$peak_number $X_thresh $Y_thresh"
sh find_waveform_peaks.sh disarm_motion_$peak_number $X_thresh $Y_thresh
i=1
while [ $i -lt 2 ]
do

cp waveform_peaks_output_x.csv disarm_xpeaks_$peak_number
cp waveform_peaks_output_y.csv disarm_ypeaks_$peak_number
#echo "input desired data points"
#read input_variable
i=$(($i+1))

done

