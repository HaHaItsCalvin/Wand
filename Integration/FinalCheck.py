 #!/usr/bin/env python

#selectfile = file(raw_input("Enter Filename: "), 'r')
#with open(raw_input("Enter Filename: "), 'r') as inputF, open ('peakCount.txt','w') as w:
#with open("AddToTraining.txt",'r') as inputF, open ('TrainingFile.txt','a') as a:
#	for i, line in enumerate(inputF):
#		a.write(line)

import filecmp
if filecmp.cmp('CueCheck.txt','Cue.txt'):
	print ("SUCCESS!! Motions done correctly!!")
	with open("FinalCheck.txt","w")as w:
		w.write("Success!!")
	with open("TestFile.txt","r") as t,open("MoreTrainingData.txt","a+") as n:
		for i, line in enumerate(t):
			if i>0:
				print("%s"%line.rstrip('\n'))
				n.write("%s"%line)
else:
	print ("FAILURE!! Better luck next time!")

with open("MoreTrainingData.txt","r+") as more:
	count=0
	for line in more:
		count+=1
		print("%d"%count)
		if count==10:
			with open ("Retrain.txt","w")as w:
				w.write("Retrain")
			break
