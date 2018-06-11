#!/bin.bash
python FinalCheck.py

if [ -f "FinalCheck.txt" ]
then
	echo "User Input Matched Motion Cue!!"
	#python Add2TrainingData.py
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

#while true; do
#	read -p "Was the motion correctly recognized?" yn
#	case $yn in
