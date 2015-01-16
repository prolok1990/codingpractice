def subset(s):
	ret=[]
	if len(s)==1:
		ret.append(s[0])
		return ret
	sb=subset(s[1:])
	sb1=[None]*len(sb)
	for i in range(len(sb)):
		if s[0]!=sb[i]:
			sb1[i]=s[0]+sb[i]
	ret=sb1+sb
	if s[0] not in sb and s[0] not in s:
		ret=ret+list(s[0])

	return ret




l=subset("aba")
for i in l:
	print i

