#!/bin/bash
python FinalCheck.py
if [ -f "FINALCHECK.txt" ]
then
			echo "User input matched motion cue!!! Success!"
			python Add2TrainingData.py;
			echo "New Training File:"
			cat TrainingFile.txt;
			#echo "Doing things";
			if [ -f "Retrain.txt" ]
			then
				echo "Retraining"
			#gcc -I ../src/include -L ../src/ -O3 modified_and_xor_train.c -o modified_and_xor_train -lfann -lm;
			#./modified_and_xor_train;
				rm Retrain.txt
			fi
			echo "removing FINALCHECK.txt"
			rm FINALCHECK.txt
fi
#while true; do
#	read -p "Was the motion correctly recognized?" yn
#	case $yn in
#		[Yy]* ) echo "Old Training File:"
#			#cat TrainingFile.txt;
#			python Add2TrainingData.py;
