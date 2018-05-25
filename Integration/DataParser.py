 #!/usr/bin/env pytho

#selectfile = file(raw_input("Enter Filename: "), 'r')
#with open(raw_input("Enter Filename: "), 'r') as inputF, open ('peakCount.txt','w') as w:
with open("DataFile.txt",'r') as inputF, open ('TestFile.txt','w') as w:
	w.write("1 4 2")
	w.write("\n")
	for i, line in enumerate(inputF):
		#Check for the faulty cases
		data=line.split(": ")
		#print(data[1].rstrip('\n'))
		w.write(data[1].rstrip('\n'))
		w.write(" ")
	w.write("\n")
#Set up a place holder; this can be whatever values; just need something to represent the "Optimal outputs for FANN purposes":
	w.write("1 1")
	w.write("\n")
	#w.write('%d\n'%lineCount)
	#w.write("Difference between 1st extrema is: ")
	#w.write('%f\n'%diff)
#	w.write('Extrema Count is %d\n' &lineCount)
#	w.write('Diff between 1st peaks: %d\n' %diff)
	#				time.append(data[0])
	#				amp.append(data[1].rstrip('\n'))
	#print "Amp Vector: ",amp
	#diff=(float(amp[1])-float(amp[0]))
	#print "Diff bewteen 1st peaks: ",diff
	#w.write("Extrema Count is: ")
	#w.write('%d\n'%lineCount)
	#w.write("Difference between 1st extrema is: ")
	#w.write('%f\n'%diff)
