# A single linked list node
class node:
    def __init__(self, data=0, nxt=None):
        self.data = data
        self.nxt = nxt

# This function inserts a node at the begin of the linked list
def insert_begin(curr_head, key):
    # allocate new node and put it's data
    new_node = node()
    new_node.data = key
    # check if the linked list is empty
    if curr_head == None:
        curr_head = new_node
    # otherwise insert the new node in the begin of the linked list
    else:
        # set next of the new node to be the head
        new_node.nxt = curr_head
        # set the new node as a head
        curr_head = new_node
    return curr_head

# This function require a node to delete the node after it in the linked list
def delete_node(curr_head, key):
    # check if the linked list is empty
    if curr_head == None:
        return curr_head
    # check if the first node in the list is the deleted node
    if curr_head.data == key:
        # get the node which it will be deleted
        temp_node = curr_head
        # shift the head to be the next node
        curr_head = curr_head.nxt
        # delete the temp node
        del temp_node
    # otherwise loop till reach the deleted node
    else:
        # get the deleted node and the prev node of it in the linked list
        curr = curr_head
        prev = None
        while curr != None and curr.data != key:
            prev = curr
            curr = curr.nxt
        # jump the deleted node
        prev.nxt = curr.nxt
        # delete the node which selected
        del curr
    return curr_head

# This function searches for a node in the linked list
def search_node(curr_head, key):
    # iterate on the nodes till reach the last node in the linked list
    curr = curr_head
    while curr != None:
        # check if the given key exists in the linked list
        if curr.data == key:
            return True
        curr = curr.nxt
    return False

# This function prints the contents of the linked list
def print_linked_list(curr_head):
    # prthe data nodes starting from head till reach the last node
    curr = curr_head
    while curr != None:
        print(curr.data, end=' ')
        curr = curr.nxt

# This function deletes all nodes in the linked list in iterative way
def delete_linked_list(curr_head):
    curr = curr_head
    while curr != None:
        curr_head = curr_head.nxt
        del curr
        curr = curr_head


# Initialize a hash table with dynamic length
n, capacity = 0, 0
# Initialize a global array pointer for heads
head = []

# Initialize the load_factor
load_factor = 0.5

# This function find the next prime of the given number
def get_next_prime(x):
    # loop for maximum 150 numbers after x to find a prime one
    for i in range(x + 1, x + 150, 1):
        is_prime = True
        # loop to check if the current number is prime
        for j in range(2, int(i**.5)+1, 1):
            if i % j == 0:
                is_prime = False
        # if the current number is prime return it
        if is_prime:
            return i
    # return the given number
    return x

# This function calculates the hash value of the given key with type string
def hash_function_str_complex(key):
    res = 0
    for i in range(len(key)):
        res = (res + 37 * ord(key[i]) * (i+1)) % capacity
    return res

# This function reinserts the elements in the hash table
def reinsert_items(temp, old_capacity):
    # loop on all items in the hash table to reinsert them again
    for i in range(old_capacity):
        # check if the current item empty
        if head[i] == None:
            continue
        # loop till insert all nodes
        curr = head[i]
        while curr != None:
            # calculate the hash value of the given key
            idx = hash_function_str_complex(curr.data)
            # insert the new element
            temp[idx] = insert_begin(temp[idx], curr.data)
            curr = curr.nxt

# This function updates the capacity of the hash table
def reserve(new_capacity):
    global capacity, head
    # Initialize a new hash table with the new capacity
    temp = [None] * new_capacity
    # store the old capacity to use it in reinserting the items
    old_capacity = capacity
    # set the current capacity of the hash table to be the new capacity
    capacity = new_capacity
    # copy the elements in the current hash table to the new hash table
    reinsert_items(temp, old_capacity)
    # delete the old hash table
    for i in range(old_capacity):
        delete_linked_list(head[i])
    del head
    # set the temp hash table with new capacity to be the hash table
    head = temp

# This function searches for an element in the hash table
def search_item(key):
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # return whether the current position in the hash table contain the given key
    return search_node(head[idx], key)

# This function inserts an element in the hash table
def insert_item(key):
    global n
    # check if the given key exists or not
    if search_item(key) == True:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # insert the new element
    head[idx] = insert_begin(head[idx], key)
    # update the size of the hash table
    n = n + 1
    # check if we need to update the capacity of the hash table
    if 1.0 * n / capacity >= load_factor:
        reserve(get_next_prime(2 * capacity))

# This function deletes an element at the given index in the hash table
def delete_item(key):
    global n
    # check if the given key exists or not
    if search_item(key) == False:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # delete the given key from it's list
    head[idx] = delete_node(head[idx], key)
    # update the size of the hash table
    n = n - 1
    # check if we need to update the capacity of the min-heap
    if n < capacity // 4:
        reserve(get_next_prime(capacity // 2))

# This function prints the contents of the hash table
def print_hash_table():
    # loop to prthe elements in the hash table
    for i in range(capacity):
        if head[i] == None:
            continue
        print("index", i, ":")
        print_linked_list(head[i])
        print()


# Functionality Testing


capacity = 2
head = [None] * capacity

print("Hash Table capacity:", capacity)
print("Hash Table size:", n)
print("----------------------------------------------------")

for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(75):
        insert_item(item)
        item += c
    print("Hash Table capacity:", capacity)
    print("Hash Table size:", n)
    print("----------------------------------------------------")

for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(75):
        if search_item(item) == False:
            print(item, "not found")
        item += c

# print_hash_table()
print("----------------------------------------------------")

for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(75):
        if j < 10:
            item += c
            continue
        delete_item(item)
        item += c
    print("Hash Table capacity:", capacity)
    print("Hash Table size:", n)
    print("----------------------------------------------------")

for i in range(13):
    c = chr(ord('a')+i)
    item = ""
    item += c
    item += c
    item += c
    for j in range(10):
        if search_item(item) == False:
            print(item, "not found")
        item += c

# print_hash_table()
print("----------------------------------------------------")
