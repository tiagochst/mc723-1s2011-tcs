from numpy import*
import sys
import getopt
import fileinput
from numpy import*

def main():
    rtt=[]
    for line in fileinput.input(['seqTime.dat']):
        line = line.split()     
        rtt.append(float(line[0])*1000) #pega tempo de echo
        
    max=0
    min=1000000
    sum=0
    for i in range(len(rtt)):
        sum = sum+float(rtt[i]);

        if(max<float(rtt[i])):
            max=float(rtt[i])
        if(min>float(rtt[i])):
            min=float(rtt[i])

    media=(float(sum)/(len(rtt))) 
    devRTT=0
    for i in range(len(rtt)):
        devRTT=devRTT+math.pow(float(rtt[i])-media,2)
    devRTT=sqrt(devRTT/len(rtt))     
    
    print "=== PING - MC823 ==="
    print "Max %.3f ms" % (float(max))
    print "Min %.3f ms" % (float(min))
    print "Media %.3f ms" % media  
    print "Desvio %.3f ms" % devRTT     

if __name__ == "__main__":
    main() 
