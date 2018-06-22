 #!/usr/bin/env python

import filecmp
if filecmp.cmp('CueCheck.txt','Cue.txt'):
	print ("SUCCESS!! Motions done correctly!!")
	with open("FinalCheck.txt","w")as w:
		w.write("Success!!")
	with open("SuccessData.txt","r") as t,open("MoreTrainingData.txt","a+") as n:
		for i, line in enumerate(t):
#				print("%s"%line.rstrip('\n'))
				n.write("%s"%line)
else:
	print ("FAILURE!! Better luck next time!")

with open("MoreTrainingData.txt","r+") as more:
	count=0
	for line in more:
		count+=1
#		print("%d"%count)
		if count==10:
			with open ("Retrain.txt","w")as w:
				w.write("Retrain")
			break
