from math import log2

# A binary heap node
class node:
    def __init__(self, data=0, parent=None, left=None, right=None):
        self.data = data
        self.parent = parent
        self.left = left
        self.right = right

# Initialize a global pointer for root and size of the heap
root = None
n = 0

# This function gets the node based on the index
def get_parent_node(curr, idx, target, level):
    # base case we reach a null node
    if curr == None:
        return None
    # return the target node
    if target == 2*idx+1 or target == 2*idx+2:
        return curr
    child = (target - (1<<level) + 1) // (1<<level)
    # repeat the same definition of get node at left or right subtrees
    if child == 2*idx+1:
        return get_parent_node(curr.left, child, target, level-1)
    if child == 2*idx+2:
        return get_parent_node(curr.right, child, target, level-1)
    return None

# This function inserts an element at the given index in the min-heap
def push(item):
    global n, root
    # update the size of the min-heap
    n = n + 1
    # the first node in the heap tree
    if n == 1:
        new_node = node()
        new_node.data = item
        root = new_node
        return
    # get the parent of the last node
    parent_last_node = get_parent_node(root, 0, n-1, int(log2(n)-1))
    # insert the new element
    new_node = node()
    new_node.data = item
    if parent_last_node.left == None:
        parent_last_node.left = new_node
    else:
        parent_last_node.right = new_node
    new_node.parent = parent_last_node
    # loop to shif the values of the parents till the root of this path
    curr = new_node
    while curr != root and curr.parent.data > curr.data:
        curr.data, curr.parent.data = curr.parent.data, curr.data
        curr = curr.parent

# This function deletes an element at index idx in the min-heap
def pop():
    global n, root
    # check if the min-heap is empty
    if n == 0:
        return
    # update the size of the min-heap
    n = n - 1
    # the first node in the heap tree
    if n == 0:
        temp = root
        del temp
        root = None
        return
    # get the last node
    parent_last_node = get_parent_node(root, 0, n, int(log2(n+1)-1))
    # delete the root of the min-heap by replace it with the last element
    if parent_last_node.right != None:
        root.data, parent_last_node.right.data = parent_last_node.right.data, root.data
        temp = parent_last_node.right
        del temp
        parent_last_node.right = None
    else:
        root.data, parent_last_node.left.data = parent_last_node.left.data, root.data
        temp = parent_last_node.left
        del temp
        parent_last_node.left = None
    # loop to shif the values of the parents till the root of this path
    curr = root
    prev = None
    while curr != prev:
        # store the prev index
        prev = curr
        # get the left and right children
        left_child = curr.left
        right_child = curr.right
        # get the index of the minimum child
        if left_child != None and left_child.data < curr.data:
            curr = left_child
        if right_child != None and right_child.data < curr.data:
            curr = right_child
        # swap the old parent with the minimum child
        prev.data, curr.data = curr.data, prev.data

# This function gets the value of the root in the min-heap
def get_root():
    # check if the min-heap is empty
    # to return the biggest integer value as an invalid value
    if n == 0:
        return float('inf')
    # otherwise return the real value
    else:
        return root.data


# Functionality Testing


print("Min-Heap root:", get_root())
push(25)
print("Min-Heap root:", get_root())
push(30)
print("Min-Heap root:", get_root())
push(15)
print("Min-Heap root:", get_root())
push(20)
print("Min-Heap root:", get_root())
push(10)
print("Min-Heap root:", get_root())
print('------------------------------------------------')

''' Expected Output:
Min-Heap root: 2147483647
Min-Heap root: 25
Min-Heap root: 25
Min-Heap root: 15
Min-Heap root: 15
Min-Heap root: 10
----------------------------------------------------
'''

while n > 0:
    pop()
    print("Min-Heap root has been deleted and the current root is: ", end='')
    print(get_root())

print("Min-Heap is empty now")
print('------------------------------------------------')

''' Expected Output:
Min-Heap root has been deleted and the current root is: 15
Min-Heap root has been deleted and the current root is: 20
Min-Heap root has been deleted and the current root is: 25
Min-Heap root has been deleted and the current root is: 30
Min-Heap root has been deleted and the current root is: 2147483647
Min-Heap is empty now
----------------------------------------------------
'''

for i in range(16, 0, -1):
    push(i)
    print("Min-Heap root:", get_root())
print('------------------------------------------------')

''' Expected Output:
Min-Heap root: 16
Min-Heap root: 15
Min-Heap root: 14
Min-Heap root: 13
Min-Heap root: 12
Min-Heap root: 11
Min-Heap root: 10
Min-Heap root: 9
Min-Heap root: 8
Min-Heap root: 7
Min-Heap root: 6
Min-Heap root: 5
Min-Heap root: 4
Min-Heap root: 3
Min-Heap root: 2
Min-Heap root: 1
----------------------------------------------------
'''

while n > 0:
    pop()
    print("Min-Heap root has been deleted and the current root is: ", end='')
    print(get_root())
print("Min-Heap is empty now")
print('------------------------------------------------')

''' Expected Output:
Min-Heap root has been deleted and the current root is: 2
Min-Heap root has been deleted and the current root is: 3
Min-Heap root has been deleted and the current root is: 4
Min-Heap root has been deleted and the current root is: 5
Min-Heap root has been deleted and the current root is: 6
Min-Heap root has been deleted and the current root is: 7
Min-Heap root has been deleted and the current root is: 8
Min-Heap root has been deleted and the current root is: 9
Min-Heap root has been deleted and the current root is: 10
Min-Heap root has been deleted and the current root is: 11
Min-Heap root has been deleted and the current root is: 12
Min-Heap root has been deleted and the current root is: 13
Min-Heap root has been deleted and the current root is: 14
Min-Heap root has been deleted and the current root is: 15
Min-Heap root has been deleted and the current root is: 16
Min-Heap root has been deleted and the current root is: 2147483647
Min-Heap is empty now
----------------------------------------------------
'''
