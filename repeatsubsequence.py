def subseq(n):
	
	dictb={}
	
	

	for i in range(len(n)):
		x=n[i]
		dictb={}
		
		f=1
		for j in range(i+1,len(n)):
				
				
			y=n[j]
			if y==x:
				f+=1
			else:
				if y not in dictb:
					dictb[y]=1
				elif f>1:
					return True
				else:
					dictb[y]+=1
	return False




print subseq("xxyy")
print subseq("abab")
print subseq("abbacc")
print subseq("cbdaghfba")
print subseq("abcdacb")







