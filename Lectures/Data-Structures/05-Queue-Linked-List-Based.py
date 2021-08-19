# A queue node
class node:
    def __init__(self, data=0, prv=None, nxt=None):
        self.data = data
        self.prv = prv
        self.nxt = nxt

# Initialize a global pointers for head and tail
head = None
tail = None

# This function adds a node at the end of the queue
def push(new_data):
    global head, tail
    # allocate node and put it's data
    new_node = node()
    new_node.data = new_data    
    # check if the queue is empty
    if head == None:
        head = new_node
        tail = new_node
    # otherwise reach the end of the queue
    else:
        # set the nxt of the last node to be the node and vice versa
        tail.nxt = new_node
        new_node.prv = tail
        # set the node as a tail
        tail = new_node

# This function deletes the first node in the queue
def pop():
    global head, tail
    # check if the queue is empty
    if head == None:
        return
    # get the node which it will be deleted
    temp_node = head
    # check if the queue has only one node
    if head == tail:
        # delete the temp node
        del temp_node
        head = None
        tail = None
    # otherwise the queue has nodes more than one
    else:
        # shift the head to be the nxt node 
        head = head.nxt
        head.prv = None
        # delete the temp node
        del temp_node

# This function returns the value of the first node in the queue
def front():
    # check if the queue is empty 
    # to return the biggest integer value as an invalid value
    if head == None:
        return float('inf')
    # otherwise return the real value
    else:
        return head.data

# This function returns the value of the last node in the queue
def back():
    # check if the queue is empty 
    # to return the biggest integer value as an invalid value
    if tail == None:
        return float('inf')
    # otherwise return the real value
    else:
        return tail.data


# Functionality Testing 

print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 2147483647 and Queue back: 2147483647
----------------------------------------------------
'''

push(10)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 10
----------------------------------------------------
'''

push(20)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 20
----------------------------------------------------
'''

push(30)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 30
----------------------------------------------------
'''

push(40)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 40
----------------------------------------------------
'''

push(50)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 50
----------------------------------------------------
'''

while head != None:
    print("Queue front:", front(), " and Queue back:", back())
    pop()
    print("queue front has been deleted")
    print("----------------------------------------------------")

print("Queue is empty now")

''' Expected Output:
Queue front: 10 and Queue back: 50
queue front has been deleted
----------------------------------------------------
Queue front: 20 and Queue back: 50
queue front has been deleted
----------------------------------------------------
Queue front: 30 and Queue back: 50
queue front has been deleted
----------------------------------------------------
Queue front: 40 and Queue back: 50
queue front has been deleted
----------------------------------------------------
Queue front: 50 and Queue back: 50
queue front has been deleted
----------------------------------------------------
Queue is empty now
'''

print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 2147483647 and Queue back: 2147483647
----------------------------------------------------
'''

push(10)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 10
----------------------------------------------------
'''

push(20)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 20
----------------------------------------------------
'''

push(30)
print("Queue front:", front(), " and Queue back:", back())
print("----------------------------------------------------")

''' Expected Output:
Queue front: 10 and Queue back: 30
----------------------------------------------------
'''

while head != None:
    print("Queue front:", front(), " and Queue back:", back())
    pop()
    print("queue front has been deleted")
    print("----------------------------------------------------")

print("Queue is empty now")

''' Expected Output:
Queue front: 10 and Queue back: 30
queue front has been deleted
----------------------------------------------------
Queue front: 20 and Queue back: 30
queue front has been deleted
----------------------------------------------------
Queue front: 30 and Queue back: 30
queue front has been deleted
----------------------------------------------------
Queue is empty now
'''
