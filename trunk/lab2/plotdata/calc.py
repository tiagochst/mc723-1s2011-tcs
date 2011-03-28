from numpy import*
import sys
import getopt
import fileinput

maq=[(0,0),(1,0),(2,0),(3,0),(4,0),(5,0),(6,0),(7,0),(8,0),(9,0),(10,0),(11,0)]
class Desempenho:
	def __init__(self, pc, time):
		self.pc = pc
		self.time = time
	
	def __repr__(self):
		return repr((self.pc, self.time))

def main(i):
	obj=[]
	obj2=[]
	for line in fileinput.input(['prog'+str(i)+'.dat']):
		if not fileinput.isfirstline():
			#print line
			line = line.split()	
			obj.append(Desempenho(eval(line[1]),eval(line[2])))
	obj2=sorted(obj,key=lambda desempenho: desempenho.time)
	print "=== Maquina"+str(i)+"====" 
	print obj2
	print "========================="
	for i in range(len(obj2)):
		maq[obj2[i].pc]=((maq[obj2[i].pc])[0]+i,maq[(obj2[i]).pc][1]+1)
		

if __name__ == "__main__":
	for i in range(1,11):
		main(i)

	for i in range(1,12):
		print (((maq[i])[0])/((maq[i])[1]))
	print maq
