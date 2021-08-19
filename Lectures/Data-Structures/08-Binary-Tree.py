# A binary tree node
class node:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

# Initialize a global pointer for root
root = None

# This function do inorder traversal of the binary tree
def inOrder(curr):
    # base case we reach a None node
    if curr == None:
        return
    # repeat the same definition of inorder traversal
    inOrder(curr.left)
    print(curr.data, end=' ')
    inOrder(curr.right)

# This function do preorder traversal of the binary tree
def preOrder(curr):
    # base case we reach a None node
    if curr == None:
        return
    # repeat the same definition of preOrder traversal
    print(curr.data, end=' ')
    preOrder(curr.left)
    preOrder(curr.right)

# This function do postorder traversal of the binary tree
def postOrder(curr):
    # base case we reach a None node
    if curr == None:
        return
    # repeat the same definition of postorder traversal
    postOrder(curr.left)
    postOrder(curr.right)
    print(curr.data, end=' ')

# This function searches if the given data in the binary tree
def search(curr, data):
    # base case we reach a None node
    if curr == None:
        return False
    # check if we find the data at the curr node
    if curr.data == data:
        return True
    # repeat the same definition of search at left and right subtrees
    left_search  = search(curr.left, data)
    right_search = search(curr.right, data)
    return left_search or right_search

# This function traverses the binary tree in postorder to delete all nodes
def delete_tree(curr):
    # base case we reach a None node
    if curr == None:
        return
    # repeat the same definition of postorder traversal
    delete_tree(curr.left)
    delete_tree(curr.right)
    del curr


# Functionality Testing

# first level of the binary tree (root only)
root = node()
root.data = 5

print("Binary Tree in-order traversal   : ", end='')
inOrder(root)
print()

print("Binary Tree pre-order traversal  : ", end='')
preOrder(root)
print()

print("Binary Tree post-order traversal : ", end='')
postOrder(root)
print()
print('------------------------------------------------')

''' Expected Output:
Binary Tree in-order traversal   : 5
Binary Tree pre-order traversal  : 5
Binary Tree post-order traversal : 5
----------------------------------------------------
'''
'''    Tree Diagram
               5
'''

# second level of the binary tree
root.left = node()
root.left.data = 7
root.right = node()
root.right.data = 11

print("Binary Tree in-order traversal   : ", end='')
inOrder(root)
print()

print("Binary Tree pre-order traversal  : ", end='')
preOrder(root)
print()

print("Binary Tree post-order traversal : ", end='')
postOrder(root)
print()
print('------------------------------------------------')

''' Expected Output:
Binary Tree in-order traversal   : 7 5 11
Binary Tree pre-order traversal  : 5 7 11
Binary Tree post-order traversal : 7 11 5
----------------------------------------------------
'''
'''    Tree Diagram
               5
          /         \
         7           11
'''

# third level of the binary tree
root.left.left = node()
root.left.left.data = 4
root.left.right = node()
root.left.right.data = 6
root.right.left = node()
root.right.left.data = 9
root.right.right = node()
root.right.right.data = 13

print("Binary Tree in-order traversal   : ", end='')
inOrder(root)
print()

print("Binary Tree pre-order traversal  : ", end='')
preOrder(root)
print()

print("Binary Tree post-order traversal : ", end='')
postOrder(root)
print()
print('------------------------------------------------')

''' Expected Output:
Binary Tree in-order traversal   : 4 7 6 5 9 11 13
Binary Tree pre-order traversal  : 5 7 4 6 11 9 13
Binary Tree post-order traversal : 4 6 7 9 13 11 5
----------------------------------------------------
'''
'''    Tree Diagram
               5
          /         \
         7           11
       /   \       /    \
      4     6     9      13
'''

if search(root, 9):
    print("element", 9, "in the tree")
else:
    print("element ", 9, "not in the tree")

if search(root, 4):
    print("element", 4, "in the tree")
else:
    print("element", 4, "not in the tree")

if search(root, 8):
    print("element", 8, "in the tree")
else:
    print("element", 8, "not in the tree")

if search(root, 3):
    print("element", 3, "in the tree")
else:
    print("element", 3, "not in the tree")
print('------------------------------------------------')

''' Expected Output:
element 9 in the tree
element 4 in the tree
element 8 not in the tree
element 3 not in the tree
----------------------------------------------------
'''

delete_tree(root)
root = None

print("Binary Tree in-order traversal   : ", end='')
inOrder(root)
print()

print("Binary Tree pre-order traversal  : ", end='')
preOrder(root)
print()

print("Binary Tree post-order traversal : ", end='')
postOrder(root)
print()
print('------------------------------------------------')

''' Expected Output:
Binary Tree in-order traversal   :
Binary Tree pre-order traversal  :
Binary Tree post-order traversal :
----------------------------------------------------
'''
