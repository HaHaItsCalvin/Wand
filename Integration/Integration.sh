#!/bin/sh

#
#
#Audio Cue goes here!!!
#Needed to know when to start the acquisition process
#
pkill gatttool
gcc -o Acquire_LowPass_Continuous Acquire_LowPass_Continuous.c -lm -lc -lliquid
echo "Begin motion data input"
./Acquire_LowPass_Continuous 0.4 1
echo "Begin Peak Find Portion"
sh find_all_waveform_peaks.sh motion_data_output.csv 100 200 500
echo "Begin Normalization of peaks"
gcc -o correct_bubble_sort_norm correct_bubble_sort_norm.c
./correct_bubble_sort_norm waveform_peaks_output_x.csv x_playtest.csv waveform_peaks_output_z.csv z_playtest.csv
echo "Begin Playtest Python Feature Discrimination"
python peakCounter.py
echo "Finished with Python Portion"
