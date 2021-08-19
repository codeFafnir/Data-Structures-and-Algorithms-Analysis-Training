# Initialize a heap with dynamic length
n, capacity, arr = 0, 0, []

# This function updates the capacity of the heap
def reserve(new_capacity):
    global arr, capacity
    # Initialize a new heap with the new capacity
    temp = [0] * new_capacity
    # copy the elements in the current heap to the new heap
    for i in range(n):
        temp[i] = arr[i]
    # delete the old heap
    del arr
    # set the temp heap with new capacity to be the heap
    arr = temp
    # set the current capacity of the heap to be the new capacity
    capacity = new_capacity

# This function inserts an element at the given index in the max-heap
def push(item):
    global n
    # check if we need to update the capacity of the max-heap
    if n == capacity:
        reserve(2 * capacity + 1)
    # insert the new element
    arr[n] = item
    # loop to shif the values of the parents till the root of this path
    i = n
    while i > 0 and arr[(i-1) // 2] < arr[i]:
        arr[(i-1) // 2], arr[i] = arr[i], arr[(i-1) // 2]
        i = (i-1) // 2
    # update the size of the max-heap
    n = n + 1

# This function deletes an element at index idx in the max-heap
def pop():
    global n
    # check if the max-heap is empty
    if n == 0:
        return
    # update the size of the max-heap
    n = n - 1
    # delete the root of the max-heap by replace it with the last element
    arr[0], arr[n] = arr[n], arr[0]
    # loop to shif the values of the parents till the root of this path
    i, j = 0, -1
    while i != j:
        # store the prev index
        j = i
        # get the index of the left and right children
        left_idx  = 2*i + 1
        right_idx = 2*i + 2
        # get the index of the maximum child
        if left_idx < n and arr[left_idx] > arr[i]:
            i = left_idx
        if right_idx < n and arr[right_idx] > arr[i]:
            i = right_idx
        # swap the old parent with the maximum child
        arr[i], arr[j] = arr[j], arr[i]
    # check if we need to update the capacity of the max-heap
    if n < capacity // 2:
        reserve(capacity // 2)

# This function gets the value of the root in the max-heap
def get_root():
    # check if the max-heap is empty
    # to return the smallest integer value as an invalid value
    if n == 0:
        return -float('inf')
    # otherwise return the real value
    else:
        return arr[0]


# Functionality Testing


print("Max-Heap root:", get_root())
push(10)
print("Max-Heap root:", get_root())
push(20)
print("Max-Heap root:", get_root())
push(15)
print("Max-Heap root:", get_root())
push(30)
print("Max-Heap root:", get_root())
push(25)
print("Max-Heap root:", get_root())
print('------------------------------------------------')

''' Expected Output:
Max-Heap root: -2147483648
Max-Heap root: 10
Max-Heap root: 20
Max-Heap root: 20
Max-Heap root: 30
Max-Heap root: 30
----------------------------------------------------
'''

while n > 0:
    pop()
    print("Max-Heap root has been deleted and the current root is: ", end='')
    print(get_root())

print("Max-Heap is empty now")
print('------------------------------------------------')

''' Expected Output:
Max-Heap root has been deleted and the current root is: 25
Max-Heap root has been deleted and the current root is: 20
Max-Heap root has been deleted and the current root is: 15
Max-Heap root has been deleted and the current root is: 10
Max-Heap root has been deleted and the current root is: -2147483648
Max-Heap is empty now
----------------------------------------------------
'''

for i in range(1, 17):
    push(i)
    print("Max-Heap root:", get_root())
print('------------------------------------------------')

''' Expected Output:
Max-Heap root: 1
Max-Heap root: 2
Max-Heap root: 3
Max-Heap root: 4
Max-Heap root: 5
Max-Heap root: 6
Max-Heap root: 7
Max-Heap root: 8
Max-Heap root: 9
Max-Heap root: 10
Max-Heap root: 11
Max-Heap root: 12
Max-Heap root: 13
Max-Heap root: 14
Max-Heap root: 15
Max-Heap root: 16
----------------------------------------------------
'''

while n > 0:
    pop()
    print("Max-Heap root has been deleted and the current root is: ", end='')
    print(get_root())

print("Max-Heap is empty now")
print('------------------------------------------------')

''' Expected Output:
Max-Heap root has been deleted and the current root is: 15
Max-Heap root has been deleted and the current root is: 14
Max-Heap root has been deleted and the current root is: 13
Max-Heap root has been deleted and the current root is: 12
Max-Heap root has been deleted and the current root is: 11
Max-Heap root has been deleted and the current root is: 10
Max-Heap root has been deleted and the current root is: 9
Max-Heap root has been deleted and the current root is: 8
Max-Heap root has been deleted and the current root is: 7
Max-Heap root has been deleted and the current root is: 6
Max-Heap root has been deleted and the current root is: 5
Max-Heap root has been deleted and the current root is: 4
Max-Heap root has been deleted and the current root is: 3
Max-Heap root has been deleted and the current root is: 2
Max-Heap root has been deleted and the current root is: 1
Max-Heap root has been deleted and the current root is: -2147483648
Max-Heap is empty now
----------------------------------------------------
'''
