# Initialize a hash table with static length
hash_table_size  = int(1e3)+13
hash_table_prime = int(1e3)+9
arr = [''] * hash_table_size

# This function calculates the hash value of the given key with type string
def hash_function_str_complex(key):
    res = 0
    for i in range(len(key)):
        res = (res + 37 * ord(key[i]) * (i+1)) % hash_table_size
    return res

# This function calculates the hash value of the given hash value
def hash_function_secondary(hash_idx):
    return hash_table_prime - hash_idx % hash_table_prime

# This function searches for an element in the hash table
def search_item(key):
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # calculate the second hash value of the given hash value
    step = hash_function_secondary(idx)
    # loop till find the given key
    i = 0
    while arr[(idx + i*step) % hash_table_size] != key and \
           arr[(idx + i*step) % hash_table_size] != "":
        i += 1
    # return whether the current position in the hash table contain the given key
    return arr[(idx + i*step) % hash_table_size] == key

# This function inserts an element in the hash table
def insert_item(key):
    # check if the given key exists or not
    if search_item(key) == True:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # calculate the second hash value of the given hash value
    step = hash_function_secondary(idx)
    # loop till find an empty position
    i = 0
    while arr[(idx + i*step) % hash_table_size] != "" and \
           arr[(idx + i*step) % hash_table_size] != "#":
        i += 1
    # insert the new element
    arr[(idx + i*step) % hash_table_size] = key

# This function deletes an element at the given index in the hash table
def delete_item(key):
    # check if the given key exists or not
    if search_item(key) == False:
        return
    # calculate the hash value of the given key
    idx = hash_function_str_complex(key)
    # calculate the second hash value of the given hash value
    step = hash_function_secondary(idx)
    # loop till find the given key
    i = 0
    while arr[(idx + i*step) % hash_table_size] != key:
        i += 1
    # set the position of the deleted element as a hash sign
    arr[(idx + i*step) % hash_table_size] = "#"

# This function prints the contents of the hash table
def print_hash_table():
    # loop to prthe elements in the hash table
    for i in range(hash_table_size):
        if arr[i] == "" or arr[i] == "#":
            continue
        print("index", i, ":", arr[i])


# Functionality Testing


for i in range(26):
    c = chr(ord('a')+i)
    item = ""
    for j in range(10):
        item += c
        insert_item(item)

for i in range(26):
    c = chr(ord('a')+i)
    item = ""
    for j in range(10):
        if search_item(item) == False:
            print(item, "not found")
        item += c

print_hash_table()
print("----------------------------------------------------")

for i in range(26):
    c = chr(ord('a')+i)
    item = ""
    for j in range(10):
        item += c
        if j < 3:
            continue
        delete_item(item)

for i in range(26):
    c = chr(ord('a')+i)
    item = ""
    for j in range(3):
        item += c
        if search_item(item) == False:
            print(item, "not found")

print_hash_table()
print("----------------------------------------------------")
