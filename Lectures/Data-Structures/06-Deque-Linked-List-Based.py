# A deque node
class node:
    def __init__(self, data=0, prv=None, nxt=None):
        self.data = data
        self.prv = prv
        self.nxt = nxt

# Initialize a global pointers for head and tail
head = None
tail = None

# This function inserts a node at the begin of the deque
def insert_begin(new_data):
    global head, tail
    # allocate node and put it's data
    new_node = node()
    new_node.data = new_data
    # check if the deque is empty
    if head == None:
        head = new_node
        tail = new_node
    # otherwise insert the node in the begin of the deque
    else:
        # set nxt of the node to be the head and vice versa
        new_node.nxt = head
        head.prv = new_node
        # set the node as a head
        head = new_node

# This function inserts a node at the end of the deque
def insert_end(new_data):
    global head, tail
    # allocate node and put it's data
    new_node = node()
    new_node.data = new_data
    # check if the deque is empty
    if head == None:
        head = new_node
        tail = new_node
    # otherwise reach the end of the deque
    else:
        # set the nxt of the last node to be the node and vice versa
        tail.nxt = new_node
        new_node.prv = tail
        # set the node as a tail
        tail = new_node

# This function deletes the first node in the deque
def delete_begin():
    global head, tail
    # check if the deque is empty
    if head == None:
        return
    # get the node which it will be deleted
    temp_node = head
    # check if the deque contain only one node
    if head == tail:
        # delete the temp node
        del temp_node
        head = None
        tail = None
    # otherwise the deque contain nodes more than one
    else:
        # shift the head to be the nxt node 
        head = head.nxt
        head.prv = None
        # delete the temp node
        del temp_node

# This function deletes the last node in the deque
def delete_end():
    global head, tail
    # check if the deque is empty
    if head == None:
        return
    # get the node which it will be deleted
    temp_node = tail
    # check if the deque contain only one node
    if head == tail:
        # delete the temp node
        del temp_node
        head = None
        tail = None
    # otherwise the deque contain nodes more than one
    else:
        # jump the deleted node
        tail = tail.prv
        tail.nxt = None
        # delete the node which selected
        del temp_node

# This function prints the contents of the deque
def print_deque():
    # prthe data nodes starting from head till reach the last node
    curr = head
    while curr != None:
        print(curr.data, end=' ')
        curr = curr.nxt

# This function returns the value of the first element in the deque
def front():
    # check if the deque is empty 
    # to return the biggest integer value as an invalid value
    if head == None:
        return float('inf')
    # otherwise return the real value
    else:
        return head.data

# This function returns the value of the last element in the deque
def back():
    # check if the deque is empty 
    # to return the biggest integer value as an invalid value
    if tail == None:
        return float('inf')
    # otherwise return the real value
    else:
        return tail.data

# This function prints the contents of the deque
def print_deque_reverse():
    # prthe data nodes starting from tail till reach the first node
    curr = tail
    while curr != None:
        print(curr.data, end=' ')
        curr = curr.prv


# Functionality Testing 

print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Deque front: 2147483647 and Deque back: 2147483647
Deque items forward:  
Deque items backward: 
----------------------------------------------------
'''

print("adding the following elements 10 20 30 40 50")
insert_end(10)
insert_end(20)
insert_end(30)
insert_end(40)
insert_end(50)
print("the above elements have been added to the deque")

''' Expected Output:
adding the following elements 10 20 30 40 50
the above elements have been added to the deque
'''

print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Deque front: 10 and Deque back: 50
Deque items forward:  10 20 30 40 50 
Deque items backward: 50 40 30 20 10 
----------------------------------------------------
'''

print("add element 60 at the end of the deque")
insert_end(60)
print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 60 at the end of the deque
Deque front: 10 and Deque back: 60
Deque items forward:  10 20 30 40 50 60 
Deque items backward: 60 50 40 30 20 10 
----------------------------------------------------
'''

print("add element 20 at the begin of the deque")
insert_begin(20)
print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 20 at the begin of the deque
Deque front: 20 and Deque back: 60
Deque items forward:  20 10 20 30 40 50 60 
Deque items backward: 60 50 40 30 20 10 20 
----------------------------------------------------
'''

print("add element 70 at the begin of the deque")
insert_begin(70)
print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 70 at the begin of the deque
Deque front: 70 and Deque back: 60
Deque items forward:  70 20 10 20 30 40 50 60 
Deque items backward: 60 50 40 30 20 10 20 70 
----------------------------------------------------
'''

print("delete the first element ")
delete_begin()
print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete the first element 
Deque front: 20 and Deque back: 60
Deque items forward:  20 10 20 30 40 50 60 
Deque items backward: 60 50 40 30 20 10 20 
----------------------------------------------------
'''

print("delete the last element ")
delete_end()
print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete the last element 
Deque front: 20 and Deque back: 20
Deque items forward:  20 10 20 30 40 50 
Deque items backward: 50 40 30 20 10 20 
----------------------------------------------------
'''

print("delete the first element ")
delete_begin()
print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete the first element 
Deque front: 10 and Deque back: 20
Deque items forward:  10 20 30 40 50 
Deque items backward: 50 40 30 20 10 
----------------------------------------------------
'''

print("delete the last element ")
delete_end()
print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete the last element 
Deque front: 10 and Deque back: 20
Deque items forward:  10 20 30 40 
Deque items backward: 40 30 20 10 
----------------------------------------------------
'''

print("deleting the following elements 10 20 30 40")
delete_end()
delete_end()
delete_end()
delete_end()
print("the above elements have been deleted from the deque")

''' Expected Output:
deleting the following elements 10 20 30 40
the above elements have been deleted from the deque
'''

print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Deque front: 2147483647 and Deque back: 2147483647
Deque items forward:  
Deque items backward: 
----------------------------------------------------
'''

print("adding the following elements 40 30 20 10")
insert_begin(10)
insert_begin(20)
insert_begin(30)
insert_begin(40)
print("the above elements have been added to the deque")

''' Expected Output:
adding the following elements 40 30 20 10
the above elements have been added to the deque
'''

print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Deque front: 40 and Deque back: 10
Deque items forward:  40 30 20 10 
Deque items backward: 10 20 30 40 
----------------------------------------------------
'''

print("deleting the following elements 40 30 20 10")
delete_begin()
delete_begin()
delete_begin()
delete_begin()
print("the above elements have been deleted from the deque")

''' Expected Output:
deleting the following elements 40 30 20 10
the above elements have been deleted from the deque
'''

print("Deque front:", front(), " and Deque back:", back())
print("Deque items forward:", end=' ')
print_deque()
print()
print("Deque items backward:", end=' ')
print_deque_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Deque front: 2147483647 and Deque back: 2147483647
Deque items forward:  
Deque items backward: 
----------------------------------------------------
'''
