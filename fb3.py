from random import randint
def largest(s):
	count=0
	if len(s)>0:
		max=s[0]
	for i in range(1,len(s)):
		if s[i]>max:
			max = s[i]
			count=1
			maxind=i
		if s[i]==max:
			count+=1
			if randint(1,count) == 1:
				maxind=i



	
	
	return (s[maxind],maxind)


print largest([1,2,3,3,3,3,2,1,3,3,1])
print largest([1,2,3,3,3,3,2,1,3,3,1])
print largest([1,2,3,3,3,3,2,1,3,3,1])
print largest([1,2,3,3,3,3,2,1,3,3,1])
print largest([1,2,3,3,3,3,2,1,3,3,1])
print largest([1,2,3,3,3,3,2,1,3,3,1])
	


