class LinkedList:
    next = None
    val = None
 
    def __init__(self, val):
        self.val = val
 
    def add(self, val):
        if self.next == None:
            self.next = LinkedList(val)
        else:
            self.next.add(val)
 
    def __str__(self):
        return "({val}) ".format(val=self.val) + str(self.next)

class BinaryTree:
    val = None
    left = None
    right = None
    
    def __init__(self, val):
        self.val = val

    def addleft(self, val):
        if self.left == None:
            self.left = BinaryTree(val)
            return True
        else:
            return False
    def addright(self, val):
        if self.right == None:
            self.right = BinaryTree(val)
            return True
        else:
            return False
 
 
    def __str__(self):
        return "<Binary Tree (val is {val}). \n\tleft is {left} \n\tright is {right}>".format(val=self.val,left=self.left,right=self.right)