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

./bubble_sort_norm_Edited patronus_xpeaks_$i patronus_xsortedpeaks_$i patronus_ypeaks_$i patronus_ysortedpeaks_$i
mv patronus_xpeaks_$i ~/Wand/patronus_motionpeaks_info
mv patronus_ypeaks_$i ~/Wand/patronus_motionpeaks_info

echo $i
i=$(($i+1))
done
