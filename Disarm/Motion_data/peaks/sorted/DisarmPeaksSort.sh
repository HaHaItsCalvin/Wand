#!/bin/sh
# To execute script sh diagargsort.sh <diagonal_angle>
# Output comes as <Diagonal Angle>Xsortedpeaks & &sortedpeaks
#

i=1
gcc -o bubble_sort_norm_Edited bubble_sort_norm_Edited.c

echo "Enter End File #"
read end
#Runs i from the initial value of i up to value less than 5
while [ $i -lt $(($end+1)) ]
do
#./bubble_sort_norm_Edited ~/IoT_ML_Design_DiagMotion_Automation/diag_peaks/"$1"Xdiag_peaks_$i "$1"Xsortedpeaks_$i ~/IoT_ML_Design_DiagMotion_Automation/diag_peaks/"$1"Ydiag_peaks_$i "$1"Ysortedpeaks_$i

./bubble_sort_norm_Edited disarm_xpeaks_$i disarm_xsortedpeaks_$i disarm_ypeaks_$i disarm_ysortedpeaks_$i
mv disarm_xsortedpeaks_$i ~/Wand/Disarm/Motion_data/peaks/sorted
mv disarm_ysortedpeaks_$i ~/Wand/Disarm/Motion_data/peaks/sorted

echo $i
i=$(($i+1))
done
