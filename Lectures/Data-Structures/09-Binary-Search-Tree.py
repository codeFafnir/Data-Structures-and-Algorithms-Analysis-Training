# A binary search tree node
class node:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

# Initialize a global pointer for root
root = None

# This function do inorder traversal of the binary search tree
def inOrder(curr):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of inorder traversal
    inOrder(curr.left)
    print(curr.data, end=' ')
    inOrder(curr.right)

# This function do preorder traversal of the binary search tree
def preOrder(curr):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of preOrder traversal
    print(curr.data, end=' ')
    preOrder(curr.left)
    preOrder(curr.right)

# This function do postorder traversal of the binary search tree
def postOrder(curr):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of postorder traversal
    postOrder(curr.left)
    postOrder(curr.right)
    print(curr.data, end=' ')

# This function searches if the given data in the binary search tree
def search(curr, data):
    # base case we reach a null node
    if curr == None:
        return False
    # check if we find the data at the curr node
    if curr.data == data:
        return True
    # repeat the same definition of search at left or right subtrees
    if data < curr.data:
        return search(curr.left, data)
    else:
        return search(curr.right, data)

# This function inserts a new node with given key in the binary search tree
def insert_node(curr, new_data):
    # base case we reach a null node
    if curr == None:
        curr = node()
        curr.data = new_data
        return curr
    # repeat the same definition of insert at left or right subtrees
    if new_data < curr.data:
        curr.left = insert_node(curr.left, new_data)
    elif new_data > curr.data:
        curr.right = insert_node(curr.right, new_data)
    # return the unchanged node pointer
    return curr

# This function returns the node with minimum value found in the given tree
def min_node(curr):
    res = curr
    # loop down to find the leftmost leaf
    while res.left != None:
        res = res.left
    # return the nearest data node of curr data node
    return res

# This function returns the node with maximum value found in the given tree
def max_node(curr):
    res = curr
    # loop down to find the rightmost leaf
    while res.right != None:
        res = res.right
    # return the nearest data node of curr data node
    return res

# This function deletes the given data in the binary search tree if exists
def delete_node(curr, data):
    # base case we reach a null node
    if curr == None:
        return curr
    # repeat the same definition of insert at left or right subtrees
    if data < curr.data:
        curr.left = delete_node(curr.left, data)
    elif data > curr.data:
        curr.right = delete_node(curr.right, data)
    # if the given data is same as curr's data, then we will delete this node
    else:
        # node with no child
        if curr.left == None and curr.right == None:
            del curr
            return None
        # node with only one child
        elif curr.left == None:
            temp = curr.right
            del curr
            return temp
        # node with only one child
        elif curr.right == None:
            temp = curr.left
            del curr
            return temp
        # node with two children
        else:
            # get the inorder successor (smallest in the right subtree)
            temp = min_node(curr.right)
            # copy the inorder successor's content to this node
            curr.data = temp.data
            # delete the inorder successor
            curr.right = delete_node(curr.right, temp.data)
    # return the unchanged node pointer
    return curr

# This function traverses the binary search tree in postorder to delete all nodes
def delete_tree(curr):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of postorder traversal
    delete_tree(curr.left)
    delete_tree(curr.right)
    del curr


# Functionality Testing


# first level of the binary search tree (root only)
root = insert_node(root, 100)

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
Binary Search Tree in-order   : 100
Binary Search Tree pre-order  : 100
Binary Search Tree post-order : 100
----------------------------------------------------
'''

# second level of the binary search tree
root = insert_node(root, 50)
root = insert_node(root, 150)

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
Binary Search Tree in-order   : 50 100 150
Binary Search Tree pre-order  : 100 50 150
Binary Search Tree post-order : 50 150 100
----------------------------------------------------
'''

# third level of the binary search tree
root = insert_node(root, 25)
root = insert_node(root, 75)
root = insert_node(root, 125)
root = insert_node(root, 175)

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
Binary Search Tree in-order   : 25 50 75 100 125 150 175
Binary Search Tree pre-order  : 100 50 25 75 150 125 175
Binary Search Tree post-order : 25 75 50 125 175 150 100
----------------------------------------------------
'''
'''    Tree Diagram
            100
          /     \
        50       150
       /  \     /   \
     25    75 125   175
'''

print("deleting node 100 ")
root = delete_node(root, 100)

'''    Tree Diagram
            125
          /     \
        50       150
       /  \         \
     25    75       175
'''

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

''' Expected Output
deleting node 100
Binary Search Tree in-order   : 25 50 75 125 150 175
Binary Search Tree pre-order  : 125 50 25 75 150 175
Binary Search Tree post-order : 25 75 50 175 150 125
----------------------------------------------------
'''

if search(root, 150):
    print("element", 150, "in the tree")
else:
    print("element", 150, "not in the tree")

if search(root, 100):
    print("element", 100, "in the tree")
else:
    print("element", 100, "not in the tree")

if search(root, 75):
    print("element", 75, "in the tree")
else:
    print("element", 75, "not in the tree")

if search(root, 95):
    print("element", 95, "in the tree")
else:
    print("element", 95, "not in the tree")
print('------------------------------------------------')

''' Expected Output
element 150 in the tree
element 100 not in the tree
element 75 in the tree
element 95 not in the tree
----------------------------------------------------
'''

print("adding the following elements 135 80 130 ")
root = insert_node(root, 135)
root = insert_node(root, 80)
root = insert_node(root, 130)

'''    Tree Diagram
              125
          /         \
        50          150
       /  \        /   \
     25    75    135   175
             \   /
             80 130
'''

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

''' Expected Output
adding the following elements 135 80 130
Binary Search Tree in-order   : 25 50 75 80 125 130 135 150 175
Binary Search Tree pre-order  : 125 50 25 75 80 150 135 130 175
Binary Search Tree post-order : 25 80 75 50 130 135 175 150 125
----------------------------------------------------
'''

print("The minimum value in the tree of root 125 is: ", end='')
print(min_node(root).data)
print("The maximum value in the tree of root 125 is: ", end='')
print(max_node(root).data)

print('------------------------------------------------')

''' Expected Output
The minimum value in the tree of root 125 is: 25
The maximum value in the tree of root 125 is: 175
----------------------------------------------------
'''

print("The minimum value in the tree of root 50  is: ", end='')
print(min_node(root.left).data)

print("The maximum value in the tree of root 50  is: ", end='')
print(max_node(root.left).data)

print("The minimum value in the tree of root 150 is: ", end='')
print(min_node(root.right).data)

print("The maximum value in the tree of root 150 is: ", end='')
print(max_node(root.right).data)

print('------------------------------------------------')

''' Expected Output
The minimum value in the tree of root 50  is: 25
The maximum value in the tree of root 50  is: 80
The minimum value in the tree of root 150 is: 130
The maximum value in the tree of root 150 is: 175
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

''' Expected Output
Binary Search Tree in-order   :
Binary Search Tree pre-order  :
Binary Search Tree post-order :
----------------------------------------------------
'''
