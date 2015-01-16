def befnumber(n):
	s= list(str(n))
	for i in range(len(s)-1,-1,-1):
		if int(s[i])>int(s[i-1]):
			for e in range(len(s)-1,i-1,-1):
				if int(s[e])>int(s[i-1]):
					temp=s[e]
					s[e]=s[i-1]
					s[i-1]=temp
					break
					
			for e in range(i,int(i+len(s))/2):
				temp=s[e]
				s[e]=s[len(s)-e+i-1]
				s[len(s)-e+i-1]=temp
				
			break
	return int("".join(s))





		


s=int(raw_input("Enter a number:"))
print befnumber(s)
