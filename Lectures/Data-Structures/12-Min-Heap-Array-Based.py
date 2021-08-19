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

# This function inserts an element at the given index in the min-heap
def push(item):
    global n
    # check if we need to update the capacity of the min-heap
    if n == capacity:
        reserve(2 * capacity + 1)
    # insert the new element
    arr[n] = item
    # loop to shif the values of the parents till the root of this path
    i = n
    while i > 0 and arr[(i-1) // 2] > arr[i]:
        arr[(i-1) // 2], arr[i] = arr[i], arr[(i-1) // 2]
        i = (i-1) // 2
    # update the size of the min-heap
    n = n + 1

# This function deletes an element at index idx in the min-heap
def pop():
    global n
    # check if the min-heap is empty
    if n == 0:
        return
    # update the size of the min-heap
    n = n - 1
    # delete the root of the min-heap by replace it with the last element
    arr[0], arr[n] = arr[n], arr[0]
    # loop to shif the values of the parents till the root of this path
    i, j = 0, -1
    while i != j:
        # store the prev index
        j = i
        # get the index of the left and right children
        left_idx  = 2*i + 1
        right_idx = 2*i + 2
        # get the index of the minimum child
        if left_idx < n and arr[left_idx] < arr[i]:
            i = left_idx
        if right_idx < n and arr[right_idx] < arr[i]:
            i = right_idx
        # swap the old parent with the minimum child
        arr[i], arr[j] = arr[j], arr[i]
    # check if we need to update the capacity of the min-heap
    if n < capacity // 2:
        reserve(capacity // 2)

# This function gets the value of the root in the min-heap
def get_root():
    # check if the min-heap is empty
    # to return the biggest integer value as an invalid value
    if n == 0:
        return float('inf')
    # otherwise return the real value
    else:
        return arr[0]


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
