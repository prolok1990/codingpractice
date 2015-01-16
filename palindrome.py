def palindrome(a):
	a=a.lower()
	la=len(a)
	
	if la!=0:
		for i in range(la/2+1):
			if a[i]!=a[la-i-1]:
				return False
		return True

	else:
		return False



a=raw_input("Enter a string")
print palindrome(a)