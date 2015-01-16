def stringmatch(s1,s2):
	i=0
	j=0
	
	if s2[0]=="*":
		return False
	while i<len(s1):
		print s1[i],s2[j]
		if s2[j]!="*":
			if s1[i]!=s2[j] and s2[j]!=".":
				return False
			i+=1
			j+=1
		else:
			
			if i==j:
				if s1[i]!=s2[j-1]:
					return False
				

			elif i>j:
				
				if s1[i]!=s2[j-1] and s1[i]!=s2[j+1]:
					return False
				else:
						if s1[i]==s2[j+1]:
							j+=2
						
				
			i+=1


	if j==len(s2):
		return True
	else:
		return False





print stringmatch("aaaaabcdf","a*abcdf")



