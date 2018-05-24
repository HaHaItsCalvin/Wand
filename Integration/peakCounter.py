 #!/usr/bin/env pytho

#selectfile = file(raw_input("Enter Filename: "), 'r')
#with open(raw_input("Enter Filename: "), 'r') as inputF, open ('peakCount.txt','w') as w:
with open("z_playtest.csv",'r') as inputF, open ('DataFile.txt','w') as w:
	time = []
	amp = []
	lineCount=0
	for i, line in enumerate(inputF):
		#Check for the faulty cases
		if i==0:
			pass
		else:
			if '-nan' in line:
				print "FAIL due to -nan input\n"
				exit()
			else:
				data=line.split(",")
				#filter out zero amplitude cases
				#Filter out cases where amplitude spikes occur at times <0.05sec
				if float(data[1])==0 or float(data[1])==-0 or float(data[0])<0.1:
					pass
				else:
					#print "ELSE\n"
					lineCount+=1
					time.append(data[0])
					amp.append(data[1].rstrip('\n'))
				#w.write(" ".join(line.split(",")))
				#time,amp=line.split(",")
				#print time,amp
#				float(time[1])
#				float(time[0])
	print "# of Peaks/Troughs: ",lineCount
	print "Time vector: ", time
	print "Amp Vector: ",amp
	diff=(float(amp[1])-float(amp[0]))
	print "Diff bewteen 1st peaks: ",diff
	w.write("Extrema Count is: ")
	w.write('%d\n'%lineCount)
	w.write("Difference between 1st extrema is: ")
	w.write('%f\n'%diff)
#	w.write('Extrema Count is %d\n' &lineCount)
#	w.write('Diff between 1st peaks: %d\n' %diff)
	if diff<0:
		print "Disarm"
		exit()
	if lineCount > 5:
			print "Shrinking"
	else:
		print "Aquamente or Patronus"
