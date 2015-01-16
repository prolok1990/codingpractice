def fibinocci(s):
	c=3
	a=1
	b=1
	if s==1:
		print a
		return
	print a
	print b


	while c<=s:
			
		temp=b
		b=a+b
		a=temp
		print b
		c+=1

def recurfib(s):
	if s==1:
		print 1
	



fibinocci(5)

