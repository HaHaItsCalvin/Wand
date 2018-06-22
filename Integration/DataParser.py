 #!/usr/bin/env pytho

#selectfile = file(raw_input("Enter Filename: "), 'r')
#with open(raw_input("Enter Filename: "), 'r') as inputF, open ('peakCount.txt','w') as w:
with open("DataFile.txt",'r') as inputF, open ('TestFile.txt','w') as w:
	w.write("1 4 2")
	w.write("\n")
	for i, line in enumerate(inputF):
		data=line.split(": ")
		w.write(data[1].rstrip('\n'))
		w.write(" ")
	w.write("\n")
#Set up a place holder; this can be whatever values; just need something to represent the "Optimal outputs for FANN purposes":
	w.write("1 1")
	w.write("\n")
