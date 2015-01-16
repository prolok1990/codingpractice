def LCS(s1,s2,n):
	dp=[[0]*len(s2)]*len(s1)
	if s1[0]==s2[0]:
		dp[0][0]=1
	for i in range(len(s1)):
		for j in range(len(s2)):
			if s1[i] == s2[j]:
				dp[i][j]=1
			else:
				dp[i][j]=False

	return dp




print hascheated("","",n)




