#!/bin/sh

#
#Copy the waveform peak info and threshold and save it to the aquamente_xpeaks & ypeaks files
#

echo "Enter Peak$"
read peak_number 
echo "Enter Xthresh"
read X_thresh
echo "Enter Ythresh"
read Y_thresh
echo "Enter Zthresh"
read Z_thresh
echo "$peak_number $X_thresh $Y_thresh $Z_thresh"
sh find_all_waveform_peaks.sh ~/Wand/aquamente/Xcorr_data/aquamente_xcorr_$peak_number $X_thresh $Y_thresh $Z_thresh
while true
do

cp waveform_peaks_output_x.csv ~/Wand/aquamente/Xcorr_data/peaks/aquamente_xpeaks_$peak_number.csv
cp waveform_peaks_output_y.csv ~/Wand/aquamente/Xcorr_data/peaks/aquamente_ypeaks_$peak_number.csv
cp waveform_peaks_output_z.csv ~/Wand/aquamente/Xcorr_data/peaks/aquamente_zpeaks_$peak_number.csv


#echo "input desired data points"
#read input_variable

done

