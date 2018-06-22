#!/bin/sh

#
#
#

python Cue.py
pkill gatttool

########Begin User Motion Acquisition########
gcc -o Acquire_LowPass_Continuous Acquire_LowPass_Continuous.c -lm -lc -lliquid
./Acquire_LowPass_Continuous 0.4 1

if grep -q FAIL "Fail.txt"; then
	exit
fi

###################################################
############Begin Peak Data Processing#############
###################################################
sh find_all_waveform_peaks.sh motion_data_output.csv 100 150 300

gcc -o correct_bubble_sort_norm correct_bubble_sort_norm.c
./correct_bubble_sort_norm waveform_peaks_output_x.csv x_playtest.csv waveform_peaks_output_z.csv z_playtest.csv

python peakCounter.py



####################################################
##############Begin XCORR CALCULATIONS##############
####################################################
sh all_compute_cross_correlation.sh 
sh find_XX_peaks.sh xcorr_output.csv 5000000 
gcc -o feature_compute_autocorrelation_s feature_compute_autocorrelation_s.c
./feature_compute_autocorrelation_s waveform_peaks_output_XX.csv DataFile.txt


python DataParser.py

gcc -I ../src/include -L ../src/ -O3 MotionRecog_and_xor_recognition.c -o Motion_FANN_Recognition -lfann -lm
./Motion_FANN_Recognition

python FinalCheck.py

if [ -f "FinalCheck.txt" ]
then
	echo "User Input Matched Motion Cue!!"
	if [ -f "Retrain.txt" ]
	then
		echo "Retraining";
		python Add2TrainingData.py
		gcc -I ../src/include -L ../src/ -O3 modified_and_xor_train.c -o modified_and_xor_train -lfann -lm;
		./modified_and_xor_train;
		rm Retrain.txt;
		rm MoreTrainingData.txt;
	fi
	rm FinalCheck.txt;
fi
