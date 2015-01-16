with open('/Users/proloknair/Downloads/words.txt') as f:
	words=f.read().splitlines()


def seqsearch(seq):
	check=""
	if len(seq) != 0:

		for i in range(len(seq)):
			check+=seq[i]

			if check in words:
				print check, seq[i+1:]
				a=seqsearch(seq[i+1:])
				if a== True:
					return True
			elif check == seq:
				return False


	else:
		return True



x= raw_input("Enter a word:")
if seqsearch(x.lower()) == True :
	print "Yes it is a sequence of words"
else:
	print "Sorry it is not"



