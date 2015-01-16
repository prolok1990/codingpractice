def sqrtbbl(n):
	oldguess=-1.0
	guess=1.0
	while (guess-oldguess)>1:
		oldguess=guess
		
		guess=(guess+n/guess)/2
	return guess



number=raw_input("Enter a number:")
print sqrtbbl(int(number))
