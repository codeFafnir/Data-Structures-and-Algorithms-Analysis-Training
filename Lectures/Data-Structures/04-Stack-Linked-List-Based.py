# A stack node
class node:
    def __init__(self, data=0, nxt=None):
        self.data = data
        self.nxt = nxt

# Initialize a global pointer for head
head = None

# This function adds a node at the begin of the stack
def push(new_data):
    global head
    # allocate node and put it's data
    new_node = node()
    new_node.data = new_data
    # check if the stack is empty
    if head == None:
        head = new_node
    # otherwise insert the node in the begin of the stack
    else:
        # set nxt of the node to be the head
        new_node.nxt = head
        # set the node as a head
        head = new_node

# This function deletes the first node in the stack
def pop():
    global head
    # check if the stack is empty
    if head == None:
        return
    # get the node which it will be deleted
    temp_node = head
    # check if the stack has only one node
    if head.nxt == None:
        # delete the temp node
        del temp_node
        head = None
    # otherwise the stack has nodes more than one
    else:
        # shift the head to be the nxt node 
        head = head.nxt
        # delete the temp node
        del temp_node

# This function returns the value of the first node in the stack
def top():
    # check if the stack is empty 
    # to return the biggest integer value as an invalid value
    if head == None:
        return float('inf')
    # otherwise return the real value
    else:
        return head.data


# Functionality Testing 

print("Stack top:", top())
print("----------------------------------------------------")

''' Expected Output:
Stack top: 2147483647
----------------------------------------------------
'''

push(10)
print("Stack top:", top())
print("----------------------------------------------------")

''' Expected Output:
Stack top: 10
----------------------------------------------------
'''

push(20)
print("Stack top:", top())
print("----------------------------------------------------")

''' Expected Output:
Stack top: 20
----------------------------------------------------
'''

push(30)
print("Stack top:", top())
print("----------------------------------------------------")

''' Expected Output:
Stack top: 30
----------------------------------------------------
'''

push(40)
print("Stack top:", top())
print("----------------------------------------------------")

''' Expected Output:
Stack top: 40
----------------------------------------------------
'''

push(50)
print("Stack top:", top())
print("----------------------------------------------------")

''' Expected Output:
Stack top: 50
----------------------------------------------------
'''

while head != None:
    print("Stack top:", top())
    pop()
    print("Stack top has been deleted")
    print("----------------------------------------------------")

print("Stack is empty now")

''' Expected Output:
Stack top: 50
Stack top has been deleted
----------------------------------------------------
Stack top: 40
Stack top has been deleted
----------------------------------------------------
Stack top: 30
Stack top has been deleted
----------------------------------------------------
Stack top: 20
Stack top has been deleted
----------------------------------------------------
Stack top: 10
Stack top has been deleted
----------------------------------------------------
Stack is empty now    
'''
