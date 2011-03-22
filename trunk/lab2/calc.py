from numpy import*


# medias dos valores
meanReal=0
meanUser=0
meanSys=0

#soma total dos valores
Real=0
User=0
Sys=0

#desvio padrao
devReal=0
devUser=0
devSys=0

x0 = []
for line in file('output.txt'):
	line = line.split()	
	x = line[1]
	x0.append(x)

#calculo da media	
for i in range(len(x0)):
	if (i%3) == 0:
		Real=Real+float(x0[i])
	elif i%3 == 1:
		User=User+float(x0[i])
	else: 
		Sys=Sys+float(x0[i])

meanReal=Real/((i+1)/3)
meanUser=User/((i+1)/3)
meanSys=Sys/((i+1)/3)



#calculo do devio padrao
for i in range(len(x0)):
	if (i%3) == 0:
		devReal=devReal+math.pow(float(x0[i])-meanReal,2)
	elif i%3 == 1:
		devUser=devUser+math.pow(float(x0[i])-meanUser,2)
	else: 
		devSys=devSys+math.pow(float(x0[i])-meanSys,2)

devUser= sqrt(devUser/i/3)
devSys= sqrt(devSys/i/3)
devReal= sqrt(devReal/i/3)


print '== Medias =='
print "Real: %.3f +- %.3f" % (meanReal,devReal)
print "User: %.3f +- %.3f" % (meanUser,devUser)
print "Sys: %.3f +- %.3f"  % (meanSys,devSys)


