with open('/Users/proloknair/Downloads/words.txt') as f:
	words=f.read().splitlines()


def seqsearch(seq):
	dp=[None]*len(seq)
	i=len(seq)-1
	check=""
	while i>=0:
		check=seq[i]+check
		
		if check in words:
			dp[i]=True
		else:
			check1=""
			for j in range(len(check)):
				check1+=check[j]
				if check1 in words:
					
					if dp[i+j+1] == True:
						dp[i]=True
						break
				elif check1 == check:
					dp[i]=False
				
		i=i-1
	print dp
	return dp[0]









x= raw_input("Enter a word:")
if seqsearch(x.lower()) == True :
	print "Yes it is a sequence of words"
else:
	print "Sorry it is not"
