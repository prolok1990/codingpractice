def anagramcheck(a,b):
 	dicta={}
 	dictb={}
 	if len(a)!=len(b):
 		return False
 	else:
 		for i in range(len(a)):
 			x=a[i]
 			y=b[i]
 			if x not in dicta:
 				dicta[x]=1
 			else:
 				dicta[x]+=1
 			if y not in dictb:
 				dictb[y]=1
 			else:
 				dictb[y]+=1
 		print dicta,dictb
 		if len(dicta)!=len(dictb):
 			return False
 		else:
 			for i in dicta:
 				if i in dictb:
 					if dicta[i]!=dictb[i]:
 						return False
 				else:
 					return False
 			else:
 				return True


def anagramcheck1(a,b):
	if sorted(a)==sorted(b):
		return True
	else:
		return False

print anagramcheck("aaba", "aaab")
print anagramcheck("abcd","deba")
print
print anagramcheck1("aaba", "aaab")
print anagramcheck1("abcd","deba")

