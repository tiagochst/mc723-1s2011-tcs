from numpy import*
import sys
import getopt
import fileinput

maq=[(0,0),(1,0),(2,0),(3,0),(4,0),(5,0),(6,0),(7,0),(8,0),(9,0),(10,0),(11,0)]
class Desempenho:
	def __init__(self,prog, pc, time):
		self.prog = prog
		self.pc = pc
		self.time = time
	
	def __repr__(self):
		return repr((self.prog,self.pc, self.time))

def main():
	obj=[]
	obj2=[]
	for i in range(1,11):
		for line in fileinput.input(['prog'+str(i)+'.dat']):
			if not fileinput.isfirstline():
			#print line
				line = line.split()	
				obj.append(Desempenho(eval(line[0]),eval(line[1]),eval(line[2])),) #numero prog,numero pc, tempo
			
	obj2=sorted(obj,key=lambda desempenho: desempenho.time)
	obj=sorted(obj2,key=lambda desempenho: desempenho.prog)
	print "=== Maquina"+str(i)+"====" 
	print obj
	print "========================="
	pos=0
	for i in range(len(obj)):
		aux=obj[i].prog
		maq[obj[i].pc]=((maq[obj[i].pc])[0]+pos,maq[(obj[i]).pc][1]+1)
		pos=pos+1
		if i!= (len(obj)-1):
			if aux!=obj[i+1].prog:
				pos=0

if __name__ == "__main__":
	main()

	for i in range(1,12):
		print float(float((maq[i])[0])/float((maq[i])[1]))
	print maq
