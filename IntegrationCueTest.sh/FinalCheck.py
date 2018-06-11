 #!/usr/bin/env pytho

#selectfile = file(raw_input("Enter Filename: "), 'r')
#with open(raw_input("Enter Filename: "), 'r') as inputF, open ('peakCount.txt','w') as w:
#with open("AddToTraining.txt",'r') as inputF, open ('TrainingFile.txt','a') as a:
#	for i, line in enumerate(inputF):
#		a.write(line)

import filecmp
with open("FINALCHECK.txt","w")as w:
	if filecmp.cmp('CueCheck.txt','Cue.txt'):
		print ("SUCCESS!! Motions done correctly!!")
		w.write("Success!!")
	else:
		print ("FAILURE!! Better luck next time!")
with open("MoreTrainingData.txt","r") as more, open("Retrain.txt","w"):
	for i, line in enumerate(more):
		count=(i/2)
		if count==5:
			w.write("Retrain")
			break
