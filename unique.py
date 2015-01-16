def unique(s):
	s=s.lower()
	map=[None]*26
	a=0
	findex=0
	lindex=1
	for i in range(len(s)):
		index=ord(s[i])-97
		if map[index]==None:
			map[index]=i
		elif map[index]<a:
			map[index]=i
		elif map[index]>=a:
			if i-a > lindex-findex:
				findex=a
				lindex=i
			a=map[index]+1
			map[index]=i
		print a

	
	print s[findex:lindex]





unique("ikshkfjdhiksljfuwjsl")




