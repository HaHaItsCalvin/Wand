Values in the TrainingFile.txt are formatted such that inputs are ordered by:

Binary 1 & 2 are used to represent the motions:

Motion		B1	B2
Shrinking	0	0
Disarm		0	1
Aquamente	1	0
Patronus	1	1

Binary 1		Binary 2
# of motion peaks      diff between first 2 extrema    # of XX Peaks

Change the filebeing fed into data= in and_xor_train.c if you wish to retrain the network with a new file
Change the filebeing fed into data= in and_xor_test.c if you wish to test the network with a new file
and_xor_test is configured to take in floating point FANN inputs and outputs
TrainFile.data holds all the values that were used to train the and_xor_test.c to recognize all motion gestures
