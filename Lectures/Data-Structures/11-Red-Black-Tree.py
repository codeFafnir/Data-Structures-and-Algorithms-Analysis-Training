RED   = 0
BLACK = 1

# Red Black tree node
class node:
    def __init__(self, data=0, color=0, left=None, right=None, parent=None):
        self.data = data
        self.color = color
        self.left = left
        self.right = right
        self.parent = parent

# Initialize a global pointer for root
root = None

# This function do inorder traversal of the Red Black tree
def inOrder(curr):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of inorder traversal
    inOrder(curr.left)
    print(curr.data, end=' ')
    inOrder(curr.right)

# This function do preorder traversal of the Red Black tree
def preOrder(curr):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of preOrder traversal
    print(curr.data, end=' ')
    preOrder(curr.left)
    preOrder(curr.right)

# This function do postorder traversal of the Red Black tree
def postOrder(curr):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of postorder traversal
    postOrder(curr.left)
    postOrder(curr.right)
    print(curr.data, end=' ')

# This function searches if the given data in the Red Black tree
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

# This function gets the grandparent of the given node in the Red Black tree
def grandparent(x):
    if x == None or x.parent == None:
        return None
    return x.parent.parent

# This function gets the sibling of the given node in the Red Black tree
def sibling(x):
    if x == None or x.parent == None:
        return None
    if x == x.parent.left:
        return x.parent.right
    else:
        return x.parent.left

# This function gets the uncle of the given node in the Red Black tree
def uncle(x):
    if x == None:
        return None
    return sibling(x.parent)

# This function gets the color of the given node in the Red Black tree
def node_color(x):
    if x == None:
        return BLACK
    return x.color

# This function computes right rotate subtree rooted with y
def right_rotate(y):
    global root
    # check if the given node and it's left branch are Nones
    if y == None or y.left == None:
        return
    # constract x and T2 pointers (check slides)
    x = y.left
    y.left = x.right
    if x.right != None:
        x.right.parent = y
    # replace node y with node x
    if y.parent == None:
        root = x
    elif y == y.parent.left:
        y.parent.left = x
    else:
        y.parent.right = x
    x.parent = y.parent
    # perform rotation
    x.right = y
    y.parent = x

# This function computes left rotate subtree rooted with x
def left_rotate(x):
    global root
    # check if the given node and it's left branch are Nones
    if x == None or x.right == None:
        return
    # constract y and T2 pointers (check slides)
    y = x.right
    x.right = y.left
    if y.left != None:
        y.left.parent = x
    # replace node x with node y
    if x.parent == None:
        root = y
    elif x == x.parent.left:
        x.parent.left = y
    else:
        x.parent.right = y
    y.parent = x.parent
    # perform rotation
    y.left = x
    x.parent = y

def insert_case1(x):
    if x.parent == None:
        x.color = BLACK
    else:
        insert_case2(x)

def insert_case2(x):
    if node_color(x.parent) == BLACK:
        return
    else:
        insert_case3(x)

def insert_case3(x):
    if node_color(uncle(x)) == RED:
        x.parent.color = BLACK
        uncle(x).color = BLACK
        grandparent(x).color = RED
        insert_case1(grandparent(x))
    else:
        insert_case4(x)

def insert_case4(x):
    if x == x.parent.right and x.parent == grandparent(x).left:
        left_rotate(x.parent)
        x = x.left
    elif x == x.parent.left and x.parent == grandparent(x).right:
        right_rotate(x.parent)
        x = x.right
    insert_case5(x)

def insert_case5(x):
    x.parent.color = BLACK
    grandparent(x).color = RED
    if x == x.parent.left and x.parent == grandparent(x).left:
        right_rotate(grandparent(x))
    else:
        left_rotate(grandparent(x))

# This function inserts a new node with given key in the Red Black tree
def insert_node(data):
    global root
    # create a new node
    new_node = node()
    new_node.data = data
    new_node.color = RED
    # if the tree is empty
    if root == None:
        root = new_node
        root.color = BLACK
        return
    curr = root
    while curr != None:
        # repeat the same definition of insert at left subtrees
        if data < curr.data:
            if curr.left == None:
                curr.left = new_node
                break
            curr = curr.left
        # repeat the same definition of insert at right subtrees
        elif data > curr.data:
            if curr.right == None:
                curr.right = new_node
                break
            curr = curr.right
        # duplicate keys are not allowed in the Red Black tree
        else:
            return
    new_node.parent = curr
    insert_case1(new_node)

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

def delete_case1(x):
    if x.parent == None:
        return
    delete_case2(x)

def delete_case2(x):
    s = sibling(x)
    if node_color(s) == RED:
        x.parent.color = RED
        s.color = BLACK
        if x == x.parent.left:
            left_rotate(x.parent)
        else:
            right_rotate(x.parent)
    delete_case3(x)

def delete_case3(x):
    s = sibling(x)
    if (x.parent.color == BLACK) and (s.color == BLACK) and \
        (node_color(s.left) == BLACK) and (node_color(s.right) == BLACK):
        s.color = RED
        delete_case1(x.parent)
    else:
        delete_case4(x)

def delete_case4(x):
    s = sibling(x)
    if (x.parent.color == RED) and (s.color == BLACK) and \
        (node_color(s.left) == BLACK) and (node_color(s.right) == BLACK):
        s.color = RED
        x.parent.color = BLACK
    else:
        delete_case5(x)

def delete_case5(x):
    s = sibling(x)
    if s.color == BLACK:
        if (x == x.parent.left) and (node_color(s.right) == BLACK) and \
            (node_color(s.left) == RED):
            s.color = RED
            s.left.color = BLACK
            right_rotate(s)
        elif (x == x.parent.right) and (node_color(s.left) == BLACK) and \
                 (node_color(s.right) == RED):
            s.color = RED
            s.right.color = BLACK
            left_rotate(s)
    delete_case6(x)

def delete_case6(x):
    s = sibling(x)
    s.color = x.parent.color
    x.parent.color = BLACK
    if x == x.parent.left:
        s.right.color = BLACK
        left_rotate(x.parent)
    else:
        s.left.color = BLACK
        right_rotate(x.parent)

def delete_child(x):
    global root
    if x == None:
        return
    # get the only child of node x
    child = None
    if x.right == None:
        child = x.left
    else:
        child = x.right
    # replace node x with node child
    if x.parent == None:
        root = child
    elif x == x.parent.left:
        x.parent.left = child
    else:
        x.parent.right = child
    if child != None:
        child.parent = x.parent
    # fix the violation if exists
    if node_color(x) == BLACK:
        if node_color(child) == RED:
            child.color = BLACK
        else:
            delete_case1(x)
    del x

# This function deletes the given data in the Red Black tree if exists
def delete_node(curr, data):
    # base case we reach a null node
    if curr == None:
        return
    # repeat the same definition of delete at left subtrees
    if data < curr.data:
        delete_node(curr.left, data)
    # repeat the same definition of delete at right subtrees
    elif data > curr.data:
        delete_node(curr.right, data)
    # if the given data is same as curr's data, then we will delete this node
    else:
        if curr.left == None or curr.right == None:
            delete_child(curr)
        else:
            # get the inorder successor (smallest in the right subtree)
            temp = min_node(curr.right)
            # copy the inorder successor's content to this node
            curr.data = temp.data
            # delete the inorder successor
            delete_node(curr.right, temp.data)

def print_tree_structure(curr, indent, last):
    if curr == None:
        return
    print(indent, end='')
    if last:
        print("R----", end='')
        indent += "   "
    else:
        print("L----", end='')
        indent += "|  "
    node_color = ("RED" if curr.color==0 else "BLACK")
    print(curr.data, "(", node_color, ")")
    print_tree_structure(curr.left, indent, False)
    print_tree_structure(curr.right, indent, True)


# Functionality Testing


for i in range(10, 101, 10):
    insert_node(i)
for i in range(200, 100, -10):
    insert_node(i)

print("Level Order Traversal of Created Tree")
print_tree_structure(root, "", True)

''' Expected Output:
Level Order Traversal of Created Tree
R----80 ( BLACK )
   L----40 ( RED )
   |  L----20 ( BLACK )
   |  |  L----10 ( BLACK )
   |  |  R----30 ( BLACK )
   |  R----60 ( BLACK )
   |     L----50 ( BLACK )
   |     R----70 ( BLACK )
   R----170 ( RED )
      L----130 ( BLACK )
      |  L----100 ( RED )
      |  |  L----90 ( BLACK )
      |  |  R----120 ( BLACK )
      |  |     L----110 ( RED )
      |  R----150 ( RED )
      |     L----140 ( BLACK )
      |     R----160 ( BLACK )
      R----190 ( BLACK )
         L----180 ( BLACK )
         R----200 ( BLACK )
'''

delete_node(root, 70)
delete_node(root, 120)
delete_node(root, 200)
delete_node(root, 190)
delete_node(root, 180)
delete_node(root, 40)

print("Level Order Traversal of Created Tree")
print_tree_structure(root, "", True)

''' Expected Output:
Level Order Traversal of Created Tree
R----80 ( BLACK )
   L----50 ( BLACK )
   |  L----20 ( RED )
   |  |  L----10 ( BLACK )
   |  |  R----30 ( BLACK )
   |  R----60 ( BLACK )
   R----130 ( RED )
      L----100 ( BLACK )
      |  L----90 ( BLACK )
      |  R----110 ( BLACK )
      R----150 ( BLACK )
         L----140 ( BLACK )
         R----170 ( BLACK )
            L----160 ( RED )
'''
