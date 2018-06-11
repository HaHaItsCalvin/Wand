 #!/usr/bin/env python
import random
#selectfile = file(raw_input("Enter Filename: "), 'r')
#with open(raw_input("Enter Filename: "), 'r') as inputF, open ('peakCount.txt','w') as w:
with open("Cue.txt",'w') as w:
	cue=random.randint(1,4)
	if cue==1:
		motion="shrinking"
		w.write("shrinking")
	elif cue==2:
		motion="patronus"
		w.write("patronus")
	elif cue==3:
		motion="aquamente"
		w.write("aquamente")
	elif cue==4:
		motion="disarm"
		w.write("disarm")
print("Do Motion: "+ motion)
print("Begin in 3 seconds!")

