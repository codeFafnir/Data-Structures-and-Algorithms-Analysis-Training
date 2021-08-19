# Initialize an deque with dynamic length
front_idx, rear_idx = 0, 0
n, capacity = 0, 0
arr = []

# This function updates the capacity of the deque
def reserve(new_capacity):
    global arr, capacity, front_idx, rear_idx
    # Initialize a deque with the capacity
    temp = [0] * new_capacity
    # copy the elements in the current deque to the deque
    for i in range(n):
        temp[i] = arr[(front_idx + i) % capacity]
    # delete the old deque
    del arr
    # set the temp deque with capacity to be the deque
    arr = temp
    # reset front_idx and rear_idx
    if n == 0:
        front_idx = rear_idx = 0
    else:
        front_idx, rear_idx = 0, n - 1
    # set the current capacity of the deque to be the capacity
    capacity = new_capacity

# This function inserts an element at the begin of the deque
def insert_begin(new_data):
    global n, front_idx, rear_idx
    # check if we need to update the capacity of the deque
    if n == capacity:
        reserve(2 * capacity + 1)
    # check if the deque is empty
    if n == 0:
        front_idx = rear_idx = 0 
    # update the front_idx of the deque
    else:
        front_idx = (front_idx - 1 + capacity) % capacity
    # insert current element into Deque 
    arr[front_idx] = new_data
    # update the size of the deque
    n = n + 1

# This function inserts an element at the end of the deque
def insert_end(new_data):
    global n, front_idx, rear_idx
    # check if we need to update the capacity of the deque
    if n == capacity:
        reserve(2 * capacity + 1)
    # check if the deque is empty
    if n == 0:
        front_idx = rear_idx = 0 
    # update the rear_idx of the deque
    else:
        rear_idx = (rear_idx + 1) % capacity
    # insert the element
    arr[rear_idx] = new_data 
    # update the size of the deque
    n = n + 1

# This function deletes the first element in the deque
def delete_begin():
    global n, front_idx, rear_idx
    # check if the deque is empty
    if n == 0:
        return
    # check if the deque has only one element 
    if front_idx == rear_idx: 
        front_idx = rear_idx = 0 
    # otherwise update the front_idx of the deque
    else:
        front_idx = (front_idx + 1) % capacity
    # update the size of the deque
    n = n - 1
    # check if we need to update the capacity of the deque
    if n < capacity // 2:
        reserve(capacity // 2)

# This function deletes the last element in the deque
def delete_end():
    global n, front_idx, rear_idx
    # check if the deque is empty
    if n == 0:
        return
    # check if the deque has only one element 
    if front_idx == rear_idx: 
        front_idx = rear_idx = 0 
    # update the rear_idx of the deque
    else:
        rear_idx = (rear_idx - 1 + capacity) % capacity
    # update the size of the deque
    n = n - 1
    # check if we need to update the capacity of the deque
    if n < capacity // 2:
        reserve(capacity // 2)

# This function returns the value of the first element in the deque
def front():
    # check if the deque is empty 
    # to return the biggest integer value as an invalid value
    if n == 0:
        return float('inf')
    # otherwise return the real value
    else:
        return arr[front_idx]

# This function returns the value of the last element in the deque
def back():
    # check if the deque is empty 
    # to return the biggest integer value as an invalid value
    if n == 0:
        return float('inf')
    # otherwise return the real value
    else:
        return arr[rear_idx]

# This function prints the contents of the deque
def print_deque():
    # loop to prthe elements in the deque
    for i in range(n):
        print(arr[(front_idx + i) % capacity], end=' ')

# This function prints the contents of the deque
def print_deque_reverse():
    # loop to prthe elements in the deque
    for i in range(n-1, -1, -1):
        print(arr[(front_idx + i) % capacity], end=' ')


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
Deque front: 20 and Deque back: 50
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
Deque front: 10 and Deque back: 50
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
Deque front: 10 and Deque back: 40
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
