 #!/usr/bin/env pytho

#selectfile = file(raw_input("Enter Filename: "), 'r')
#with open(raw_input("Enter Filename: "), 'r') as inputF, open ('peakCount.txt','w') as w:
#with open("AddToTraining.txt",'r') as inputF, open ('TrainingFile.txt','a') as a:
#	for i, line in enumerate(inputF):
#		a.write(line)

with open ('MoreTrainingData.txt','r') as inputF, open ('TrainingFile.txt','a') as a:
	for i, line in enumerate(inputF):
#		print(line)
		a.write(line)



with open ('TrainingFile.txt','r') as a, open ('NewTrainingFile.txt','w') as w:
	for i, line in enumerate(a):
		if i==0:
			data=line.split(" ")
			data[0]=int(data[0])+1
			w.write("%d"%data[0])
			w.write(" ")
			w.write("%s"%data[1])
			w.write(" ")
			w.write("%s"%data[2])
		else:
			data=line
			data.rstrip('\n')
			w.write(data)
	print("Add.py Done")



with open ('NewTrainingFile.txt','r') as r, open ('TrainingFile.txt','w') as w:
	for i, line in enumerate(r):
		data=line
		data.rstrip('\n')
		w.write(data)
print("NewTraininFile named")
#with open ('TrainingFile.txt','w') as w:
#			w.write("%d"%data[0])
#			w.write(" ")
#			w.write("%s"%data[1])
#			w.write(" ")
#			w.write("%s"%data[2])

