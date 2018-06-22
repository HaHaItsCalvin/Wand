 #!/usr/bin/env pytho

with open("z_playtest.csv",'r') as inputFz, open("x_playtest.csv",'r') as inputFx, open ('DataFile.txt','w') as w:
	timeZ = []
	timeX = []
	ampZ = []
	ampX = []
	lineCountZ=0
	lineCountX=0
	for i, line in enumerate(inputFz):
		#Check for the faulty cases
		if i==0:
			pass
		else:
			if '-nan' in line:
				print "FAIL due to -nan input\n"
				exit()
			else:
				dataZ=line.split(",")
				#filter out zero amplitude cases
				#Filter out cases where amplitude spikes occur at times <0.05sec
				if float(dataZ[1])==0 or float(dataZ[1])==-0 or float(dataZ[0])<0.1:
					pass
				else:
					lineCountZ+=1
					timeZ.append(dataZ[0])
					ampZ.append(dataZ[1].rstrip('\n'))
	for i, line in enumerate(inputFx):
		if i==0:
			pass
		else:
			if '-nan' in line:
				print "FAIL due to -nan input\n"
				exit()
			else:
				dataX=line.split(",")
				if float (dataX[1]==0) or float(dataX[1]==-0):
					pass
				else:
					lineCountX+=1
					timeX.append(dataX[0])
					ampX.append(dataX[1].rstrip('\n'))
	diffZ=(float(ampZ[1])-float(ampZ[0]))
	w.write("Z Extrema Count is: ")
	w.write('%d\n'%lineCountZ)
	w.write("Difference between 1st Z extrema is: ")
	w.write('%f\n'%diffZ)
	
	
	diffX=(float(ampX[1])-float(ampX[0]))
	w.write("Difference between 1st X extrema is: ")
	w.write('%f\n'%diffX)


#	if diffZ<0:
#		print "Disarm\n"
#		exit()
#	elif lineCountZ > 5:
#			print "Shrinking\n"
#	elif diffX<0:
#		print "Patronus\n"
#	else:
#		print "Aquamente\n"
