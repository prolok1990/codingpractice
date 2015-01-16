def anagramlist(s):
	dicta={}
	hashlist=[]
	anagramlist=[]
	for i in range(len(s)):
		for j in range(len(s[i])):
			if s[i][j] not in dicta:
				dicta[s[i][j]]=1
			else:
				dicta[s[i][j]]+=1
		hashlist.append(dicta)
		dicta={}

	a=[]
	temp=[]
	
	i=0
	j=1
	for i in range(len(s)):
		temp=[]

		if s[i] not in a:
			temp.append(s[i])
			for j in range(i+1,len(s)):
				if s[j] not in a:
					if hashlist[i]==hashlist[j]:
						temp.append(s[j])
						a.append(s[j])
				
			anagramlist.append(temp)
		
		

	return anagramlist











print anagramlist(["car", "tree", "boy", "girl", "arc","lirg","rac","yob","etre"])
