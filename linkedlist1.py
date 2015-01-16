from LinkedListTree import LinkedList

def reverselink(link1):
	last = None
	current=link1
	nex=link1.next
	while nex!= None:
		current.next=last
		last=current
		current=nex
		nex=nex.next
	current.next=last
		
		
	return current


def printlinklist(link1):
	i=1
	while link1!=None:
		print link1.val
		link1=link1.next
		if i>10000:
			break
		i+=1



def reverseprint(linkl):
	l1=reverselink(linkl)
	printlinklist(l1)
	return reverselink(l1)


l1=LinkedList(5)
l2=l1
for i in range(6):
	l2.add(i)
	l2=l2.next


print

l4=reverseprint(l1)
print
printlinklist(l4)



