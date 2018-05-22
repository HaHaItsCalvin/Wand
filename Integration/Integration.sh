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
sh find_all_waveform_peaks.sh motion_data_output.csv 100 200 300
echo "Begin Normalization of peaks"
gcc -o correct_bubble_sort_norm correct_bubble_sort_norm.c
./correct_bubble_sort_norm waveform_peaks_output_x.csv x_playtest.csv waveform_peaks_output_z.csv z_playtest.csv
echo "Begin Playtest Python Feature Discrimination"
python peakCounter.py
echo "Finished with Python Portion"
echo "Begin XCorr & AutoCorr Section"
sh all_compute_cross_correlation.sh 
echo "Finished with Xcorr & Autocorr Calculations"


gcc -o 1ZZ_peak_find 1ZZ_peak_find.c -lm
echo "Begin searching for XXPeaks"
sh find_XX_peaks.sh xcorr_output.csv 5000000 
echo "End Searching for XXPeaks"
