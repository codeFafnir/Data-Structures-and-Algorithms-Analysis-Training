# Initialize a stack with dynamic length
n = 0
capacity = 0
arr = []

# This function updates the capacity of the stack
def reserve(new_capacity):
    global arr, capacity
    # Initialize a stack with the capacity
    temp = [0] * new_capacity
    # copy the elements in the current stack to the stack
    for i in range(n):
        temp[i] = arr[i]
    # delete the old stack
    del arr
    # set the temp stack with capacity to be the stack
    arr = temp
    # set the current capacity of the stack to be the capacity
    capacity = new_capacity

# This function inserts an element at the begin of the stack
def push(new_data):
    global n
    # check if we need to update the capacity of the stack
    if n == capacity:
        reserve(2 * capacity + 1)
    # insert the element
    arr[n] = new_data
    # update the size of the stack
    n = n + 1

# This function deletes the first element in the stack
def pop():
    global n
    # check if the stack is empty
    if n == 0:
        return
    # update the size of the stack
    n = n - 1
    # check if we need to update the capacity of the stack
    if n < capacity // 2:
        reserve(capacity // 2)

# This function returns the value of the first element in the stack
def top():
    # check if the stack is empty 
    # to return the biggest integer value as an invalid value
    if n == 0:
        return float('inf')
    # otherwise return the real value
    else:
        return arr[n-1]


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

while n > 0:
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

while n > 0:
    print("Stack top:", top())
    pop()
    print("Stack top has been deleted")
    print("----------------------------------------------------")

print("Stack is empty now")

''' Expected Output:
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
