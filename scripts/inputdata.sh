#!/bin/sh

#Takes two input values and appends them to SimpleTrainingData.txt
#

echo "Enter File Name"
read filename
while true; 
do

echo "Enter Data values"
read input_variable
echo "Enter Diagonal Motion Values"
read diagonal_variable
echo "You entered: $input_variable & $diagonal_variable"
echo $input_variable >> $filename
echo $diagonal_variable >> $filename
#echo "input desired data points"
#read input_variable
done
