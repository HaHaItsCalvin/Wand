#!/bin/sh
# To execute script sh diagargsort.sh <diagonal_angle>
# Output comes as <Diagonal Angle>Xsortedpeaks & &sortedpeaks
#

i=1
gcc -o Xcorr_Peaks_Sort Xcorr_Peaks_Sort.c

echo "Enter End File #"
read end
#Runs i from the initial value of i up to value less than 5
while [ $i -lt $(($end+1)) ]
do
#./bubble_sort_norm_Edited ~/IoT_ML_Design_DiagMotion_Automation/diag_peaks/"$1"Xdiag_peaks_$i "$1"Xsortedpeaks_$i ~/IoT_ML_Design_DiagMotion_Automation/diag_peaks/"$1"Ydiag_peaks_$i "$1"Ysortedpeaks_$i

./Xcorr_Peaks_Sort patronus_XcorrPeaks_$i patronus_SortedXcorrPeaks_$i
mv patronus_SortedXcorrPeaks_$i ~/Wand/Patronus/Xcorr_data/Peaks/Sorted

echo $i
i=$(($i+1))
done
