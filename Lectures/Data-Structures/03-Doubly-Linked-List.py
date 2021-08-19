# A doubly linked list node
class node:
    def __init__(self, data=0, prv=None, nxt=None):
        self.data = data
        self.prv = prv
        self.nxt = nxt

# Initialize a global pointers for head and tail
head = None
tail = None

# This function inserts a node at the begin of the linked list
def insert_begin(new_data):
    global head, tail
    # allocate new node and put it's data
    new_node = node()
    new_node.data = new_data
    # check if the linked list is empty
    if head == None:
        head = new_node
        tail = new_node
    # otherwise insert the new node in the begin of the linked list
    else:
        # set nxt of the new node to be the head and vice versa
        new_node.nxt = head
        head.prv = new_node
        # set the new node as a head
        head = new_node

# This function inserts a node at the end of the linked list
def insert_end(new_data):
    global head, tail
    # allocate new node and put it's data
    new_node = node()
    new_node.data = new_data
    # check if the linked list is empty
    if head == None:
        head = new_node
        tail = new_node
    # otherwise reach the end of the linked list
    else:
        # set the nxt of the last node to be the new node and vice versa
        tail.nxt = new_node
        new_node.prv = tail
        # set the new node as a tail
        tail = new_node

# This function require a node to add the new node after it in the linked list
def insert_node(prv_node, new_data):
    # check if the given prv node is None
    if prv_node == None:
        return
    # allocate new node and put it's data
    new_node = node()
    new_node.data = new_data
    # set the nxt of the new node to be the nxt of the prv node and vice versa
    new_node.nxt = prv_node.nxt
    # check if the prv node is not the last node in the linked list
    if prv_node.nxt != None:
        prv_node.nxt.prv = new_node
    # move the nxt of the prv node to be the new node and vice versa
    prv_node.nxt = new_node
    new_node.prv = prv_node

# This function deletes the first node in the linked list
def delete_begin():
    global head, tail
    # check if the linked list is empty
    if head == None:
        return
    # get the node which it will be deleted
    temp_node = head
    # check if the linked list has only one node
    if head == tail:
        # delete the temp node
        del temp_node
        head = None
        tail = None
    # otherwise the linked list has nodes more than one
    else:
        # shift the head to be the nxt node 
        head = head.nxt
        head.prv = None
        # delete the temp node
        del temp_node

# This function deletes the last node in the linked list
def delete_end():
    global head, tail
    # check if the linked list is empty
    if head == None:
        return
    # get the node which it will be deleted
    temp_node = tail
    # check if the linked list has only one node
    if head == tail:
        # delete the temp node
        del temp_node
        head = None
        tail = None
    # otherwise the linked list has nodes more than one
    else:
        # jump the deleted node
        tail = tail.prv
        tail.nxt = None
        # delete the node which selected
        del temp_node

# This function require a node to delete the node after it in the linked list
def delete_node(prv_node):
    # check if the given prv node is None
    if prv_node == None or prv_node.nxt == None:
        return
    # get the deleted node in the linked list
    temp_node = prv_node.nxt    
    # jump the deleted node
    prv_node.nxt = temp_node.nxt
    # check if the temp node is not the last node in the linked list
    if temp_node.nxt != None:
        temp_node.nxt.prv = prv_node
    # delete the node which selected
    del temp_node

# This function searches for a node in the linked list
def search_node(key):
    # iterate on the nodes till reach the last node in the linked list
    curr = head
    while curr != None:
        # check if the given key exists in the linked list
        if curr.data == key:
            return True
        curr = curr.nxt
    return False

# This function prints the contents of the linked list
def print_linked_list():
    # print the data nodes starting from head till reach the last node
    curr = head
    while curr != None:
        print(curr.data, end=' ')
        curr = curr.nxt

# This function prints the contents of the linked list
def print_linked_list_reverse():
    # print the data nodes starting from tail till reach the first node
    curr = tail
    while curr != None:
        print(curr.data, end=' ')
        curr = curr.prv


# Functionality Testing

print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Linked List items forward:  
Linked List items backward: 
----------------------------------------------------
'''

print("adding the following elements 10 20 30 40 50")
insert_end(10)
insert_end(20)
insert_end(30)
insert_end(40)
insert_end(50)
print("the above elements have been added to the linked list")

''' Expected Output:
adding the following elements 10 20 30 40 50
the above elements have been added to the linked list
'''

print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Linked List items forward:  10 20 30 40 50 
Linked List items backward: 50 40 30 20 10 
----------------------------------------------------    
'''

print("add element 60 at the end of the linked list")
insert_end(60)
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 60 at the end of the linked list
Linked List items forward:  10 20 30 40 50 60 
Linked List items backward: 60 50 40 30 20 10 
----------------------------------------------------
'''

print("add element 20 at the begin of the linked list")
insert_begin(20)
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 20 at the begin of the linked list
Linked List items forward:  20 10 20 30 40 50 60 
Linked List items backward: 60 50 40 30 20 10 20 
----------------------------------------------------
'''

print("add element 70 at position 4 : ")
insert_node(head.nxt.nxt.nxt, 70)
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 70 at position 4 : 
Linked List items forward:  20 10 20 30 70 40 50 60 
Linked List items backward: 60 50 40 70 30 20 10 20 
----------------------------------------------------
'''

print("add element 90 at position 7 : ")
insert_node(head.nxt.nxt.nxt.nxt.nxt.nxt, 90)
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
add element 90 at position 7 : 
Linked List items forward:  20 10 20 30 70 40 50 90 60 
Linked List items backward: 60 90 50 40 70 30 20 10 20 
----------------------------------------------------
'''

print("delete the first element ")
delete_begin()
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete the first element 
Linked List items forward:  10 20 30 70 40 50 90 60 
Linked List items backward: 60 90 50 40 70 30 20 10 
----------------------------------------------------
'''

print("delete the last element ")
delete_end()
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete the last element 
Linked List items forward:  10 20 30 70 40 50 90 
Linked List items backward: 90 50 40 70 30 20 10 
----------------------------------------------------
'''

print("delete element at position 3 : ")
delete_node(head.nxt.nxt)
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete element at position 3 : 
Linked List items forward:  10 20 30 40 50 90 
Linked List items backward: 90 50 40 30 20 10 
----------------------------------------------------
'''

print("delete element at position 2 : ")
delete_node(head.nxt)
print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
delete element at position 2 : 
Linked List items forward:  10 20 40 50 90 
Linked List items backward: 90 50 40 20 10 
----------------------------------------------------
'''

if search_node(40):
    print("element", 40, "in the linked list")
else:
    print("element", 40, "not in the linked list")

if search_node(100):
    print("element", 100, "in the linked list")
else:
    print("element", 100, "not in the linked list")
print("----------------------------------------------------")

''' Expected Output:
element 40 in the linked list
element 100 not in the linked list
----------------------------------------------------
'''

print("deleting the following elements 10 20 40 50 90")
delete_end()
delete_end()
delete_end()
delete_end()
delete_end()
print("the above elements have been deleted from the linked list")

''' Expected Output:
deleting the following elements 10 20 40 50 90
the above elements have been deleted from the linked list
'''

print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Linked List items forward:  
Linked List items backward: 
----------------------------------------------------
'''

print("adding the following elements 30 20 10")
insert_begin(10)
insert_begin(20)
insert_begin(30)
print("the above elements have been added to the linked list")

''' Expected Output:
adding the following elements 30 20 10
the above elements have been added to the linked list
'''

print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Linked List items forward:  30 20 10 
Linked List items backward: 10 20 30 
----------------------------------------------------
'''

print("deleting the following elements 30 20 10")
delete_begin()
delete_begin()
delete_begin()
print("the above elements have been deleted from the linked list")

''' Expected Output:
deleting the following elements 30 20 10
the above elements have been deleted from the linked list
'''

print("Linked List items forward:", end=' ')
print_linked_list()
print()
print("Linked List items backward:", end=' ')
print_linked_list_reverse()
print()
print("----------------------------------------------------")

''' Expected Output:
Linked List items forward:  
Linked List items backward: 
----------------------------------------------------
'''
