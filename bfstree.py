from LinkedListTree import BinaryTree
from LinkedListTree import LinkedList


def bfstree(tree):
	queue=[]
	queue.append(tree)
	i=0
	while (len(queue)!=0):
		bf=queue.pop(0)
		print bf.val
		if bf.left != None :
			queue.append(bf.left)
		if bf.right != None :
			queue.append(bf.right)
		if i == 10000:
			break
def dfstree(tree):
	if tree==None:
		return
	else:
		print tree.val
		dfstree(tree.left)
		dfstree(tree.right)

def lca(tree,a,b):
	if tree == None:
		return 0
	
	
	leftt=lca(tree.left,a,b)
	rightt=lca(tree.right,a,b)
	if tree.val==a or tree.val==b:

		if leftt==1 or rightt==1:
			print "The Least Common Ancestor is",tree.val
			return 0
		else:
			return 1
	if  leftt == 1 and rightt == 1:
		print "The Least Common Ancestor is",tree.val
		return 0
	elif leftt==1 or rightt==1:
		return 1
	return 0
	
def inorder(a):
	if a.left!=None:
		inorder(a.left)
		print ",",
	print a.val,
	if a.right!=None:
		print ",",
		inorder(a.right)
	if a.val==5:
		print "."





tree1=BinaryTree(5)
tree1.addleft(6)
tree1.addright(7)
tree2=tree1.left
tree3=tree1.right
tree1.left.addleft(2)
tree1.left.addright(7)
tree1.right.addright(8)
tree1.right.addleft(1)
tree2.left.addleft(12)
tree2.left.addright(17)
tree2.right.addright(15)
tree2.right.addleft(11)
tree3.left.addleft(22)
tree3.left.addright(27)
tree3.right.addright(25)


print 
inorder(tree1)