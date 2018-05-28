#!/bin/.sh

while true; do
	read -p "Was the motion correctly recognized?" yn
	case $yn in
		[Yy]* ) python Add2TrainingData.py;
			echo "Doing things";
			gcc -I ../src/include -L ../src/ -O3 modified_and_xor_train.c -o modified_and_xor_train -lfann -lm;
			./modified_and_xor_train;
			break;;
		[Nn]* ) exit;;
		* ) echo "Please answer yes or no.";;
	esac
done
