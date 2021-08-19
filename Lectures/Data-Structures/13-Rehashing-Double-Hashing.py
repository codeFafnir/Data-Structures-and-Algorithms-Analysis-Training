# Initialize a hash table with dynamic length
n, capacity, prime_capacity, arr = 0, 0, 0, []

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

# This function calculates the hash value of the given hash value
def hash_function_secondary(hash_idx):
    return prime_capacity - hash_idx % prime_capacity

# This function reinserts the elements in the hash table
def reinsert_items(temp, old_capacity):
    # loop on all items in the hash table to reinsert them again
    for i in range(old_capacity):
        # check if the current item empty
        if arr[i] == "" or arr[i] == "#":
            continue
        # calculate the hash value of the given key
        idx = hash_function_str_complex(arr[i])
        # calculate the second hash value of the given hash value
        step = hash_function_secondary(idx)
        # loop till find an empty position
        j = 0
        while temp[(idx + j*step) % capacity] != "":
            j += 1
        # insert the new element
        temp[(idx + j*step) % capacity] = arr[i]

# This function updates the capacity of the hash table
def reserve(new_capacity):
    global arr, capacity
    # Initialize a new hash table with the new capacity
    temp = [''] * new_capacity
    # store the old capacity to use it in reinserting the items
    old_capacity = capacity
    # set the current capacity of the hash table to be the new capacity
    capacity = new_capacity
    # copy the elements in the current hash table to the new hash table
    reinsert_items(temp, old_capacity)
    # delete the old hash table
    del arr
    # set the temp hash table with new capacity to be the hash table
    arr = temp

# This function searches for an element in the hash table
def search_item(key):
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # calculate the second hash value of the given hash value
    step = hash_function_secondary(idx)
    # loop till find the given key
    i = 0
    while arr[(idx + i*step) % capacity] != key and \
           arr[(idx + i*step) % capacity] != "":
        i += 1
    # return whether the current position in the hash table contain the given key
    return arr[(idx + i*step) % capacity] == key

# This function inserts an element in the hash table
def insert_item(key):
    global n, prime_capacity
    # check if the given key exists or not
    if search_item(key) == True:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # calculate the second hash value of the given hash value
    step = hash_function_secondary(idx)
    # loop till find an empty position
    i = 0
    while arr[(idx + i*step) % capacity] != "" and \
           arr[(idx + i*step) % capacity] != "#":
        i += 1
    # insert the new element
    arr[(idx + i*step) % capacity] = key
    # update the size of the hash table
    n = n + 1
    # check if we need to update the capacity of the hash table
    if 1.0 * n / capacity >= load_factor:
        prime_capacity = get_next_prime(2 * capacity)
        reserve(get_next_prime(prime_capacity))

# This function deletes an element at the given index in the hash table
def delete_item(key):
    global n, prime_capacity
    # check if the given key exists or not
    if search_item(key) == False:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # calculate the second hash value of the given hash value
    step = hash_function_secondary(idx)
    # loop till find the given key
    i = 0
    while arr[(idx + i*step) % capacity] != key:
        i += 1
    # set the position of the deleted element as a hash sign
    arr[(idx + i*step) % capacity] = "#"
    # update the size of the hash table
    n = n - 1
    # check if we need to update the capacity of the min-heap
    if n < capacity // 4:
        prime_capacity = get_next_prime(capacity // 2)
        reserve(get_next_prime(prime_capacity))

# This function prints the contents of the hash table
def print_hash_table():
    # loop to prthe elements in the hash table
    for i in range(capacity):
        if arr[i] == "" or arr[i] == "#":
            continue
        print("index", i, ":", arr[i])


# Functionality Testing


capacity = 3
prime_capacity = 2
arr = [''] * capacity

print("Hash Table capacity:", capacity)
print("Hash Table prime_capacity:", prime_capacity)
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
    print("Hash Table prime_capacity:", prime_capacity)
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
    print("Hash Table prime_capacity:", prime_capacity)
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
