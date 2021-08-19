# Initialize a queue with dynamic length
front_idx, rear_idx = 0, 0
n, capacity = 0, 0
arr = []

# This function updates the capacity of the queue
def reserve(new_capacity):
    global arr, capacity, front_idx, rear_idx
    # Initialize a queue with the capacity
    temp = [0] * new_capacity
    # copy the elements in the current queue to the queue
    for i in range(n):
        temp[i] = arr[(front_idx + i) % capacity]
    # delete the old queue
    del arr
    # set the temp queue with capacity to be the queue
    arr = temp
    # reset front_idx and rear_idx
    if n == 0:
        front_idx = rear_idx = 0
    else:
        front_idx, rear_idx = 0, n - 1
    # set the current capacity of the queue to be the capacity
    capacity = new_capacity

# This function inserts an element at the begin of the queue
def push(new_data):
    global n, front_idx, rear_idx
    # check if we need to update the capacity of the queue
    if n == capacity:
        reserve(2 * capacity + 1)
    # check if the queue is empty
    if n == 0:
        front_idx = rear_idx = 0 
    # update the rear_idx of the queue
    else:
        rear_idx = (rear_idx + 1) % capacity
    # insert the element
    arr[rear_idx] = new_data 
    # update the size of the queue
    n = n + 1

# This function deletes the first element in the queue
def pop():
    global n, front_idx, rear_idx
    # check if the queue is empty
    if n == 0:
        return
    # check if the queue has only one element 
    if front_idx == rear_idx: 
        front_idx = rear_idx = 0 
    # otherwise update the front_idx of the queue
    else:
        front_idx = (front_idx + 1) % capacity 
    # update the size of the queue
    n = n - 1
    # check if we need to update the capacity of the queue
    if n < capacity // 2:
        reserve(capacity // 2)

# This function returns the value of the first element in the queue
def front():
    # check if the queue is empty 
    # to return the biggest integer value as an invalid value
    if n == 0:
        return float('inf')
    # otherwise return the real value
    else:
        return arr[front_idx]

# This function returns the value of the last element in the queue
def back():
    # check if the queue is empty 
    # to return the biggest integer value as an invalid value
    if n == 0:
        return float('inf')
    # otherwise return the real value
    else:
        return arr[rear_idx]


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

while n > 0:
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

while n > 0:
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
