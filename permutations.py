def sum(s):
	if s<10:
		return s
	else:
		return s%10+sum(s/10)




print sum(123567)
