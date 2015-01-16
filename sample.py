from random import random
def p(one): # probability of 1 in one normalized to 1
	if random()<one:
		return 1
	else:
		return 0

def pa():
	return 0.1
	

def pb_a(a):
	if a==0:
		return 0.1
	if a==1:
		return 0.9

def pc_a(a):
	if a==0:
		return 0.1
	if a==1:
		return 0.9
def pd_bc(b,c):
	if b==0 and c==0:
		return 0.01
	if b==0 and c==1:
		return 0.9

	if b==1 and c==0:
		return 0.9

	if b==1 and c==1:
		return 0.95

def pabcd(a,b,c,d):
	if a==1:
		pa1=pa()
	elif a==0:
		pa1=1-pa()
	if b==1:
		pb1=pb_a(a)
	elif b==0:
		pb1=1-pb_a(a)
	if c==1:
		pc1=pc_a(a)
	elif c==0:
		pc1=1-pc_a(a)
	if d==1:
		pd1=pd_bc(b,c)
	elif d==0:
		pd1=1-pd_bc(b,c)

	return pa1*pb1*pc1*pd1

def pbcd(b,c,d):
	return pabcd(0,b,c,d)+pabcd(1,b,c,d)

def logicsample():
	
	t=1
	while t<=10:
		a=p(pa())
		b=p(pb_a(a))
		c=p(pc_a(a))
		d=p(pd_bc(b,c))
		
		print a,b,c,d
		t=t+1
	

def gibbssample():
	a=p(0.5) # randomly assigning value for a 
	b=p(0.5) # randomly assigning value for b
	c=p(0.5) # randomly assigning value for c
	d=0 # fixing the evidence
	t=1
	count=0

	while t<=10:
		proba=pabcd(1,b,c,d)/(pabcd(0,b,c,d)+pabcd(1,b,c,d))
		a=p(proba)
		probb=pabcd(a,1,c,d)/(pabcd(a,0,c,d)+pabcd(a,1,c,d))
		b=p(probb)
		probc=pabcd(a,b,1,d)/(pabcd(a,b,0,d)+pabcd(a,b,1,d))
		c=p(probc)
		
		print a,b,c,d
		
		t=t+1
	


def gibbscutsetsample():
	 
	b=p(0.5) # randomly assigning value for b
	c=p(0.5) # randomly assigning value for c
	d=0 # fixing the evidence
	t=1
	countb=0
	countc=0
	sumpb=0
	sumpc=0

	while t<=10:
		
		probb=p(pbcd(1,c,d)/(pbcd(0,c,d)+pbcd(1,c,d)))
		b=p(probb)
		probc=p(pbcd(b,1,d)/(pbcd(b,0,d)+pbcd(b,1,d)))
		c=p(probc)
		if b==1:
			countb+=1
			sumpb+=probb
		if c==1:
			countc+=1
			sumpc+=probc

		a=p(pabcd(1,b,c,0)+pabcd(1,b,c,0))
		print a,b,c,d
		
		t=t+1
	print countb/10.0,countc/10.0 #Counting
	print sumpb/10.0,sumpc/10.0 #mixture estimator
	

logicsample()
print
gibbssample()
print 
gibbscutsetsample()






