table_size = int(1e5)+3

# This function calculates the hash value of the given key with type int
def hash_function_int(x):
    return x % table_size

# This function calculates the hash value of the given key with type int
def hash_function_int_complex(x):
    return (37 * (x % table_size)) % table_size

# This function calculates the hash value of the given key with type 
def hash_function_long( x):
    return x % table_size

# This function calculates the hash value of the given key with type 
def hash_function_long_complex( x):
    return (37 * (x % table_size)) % table_size

# This function calculates the hash value of the given key with type char
def hash_function_char(x):
    return ord(x) % table_size

# This function calculates the hash value of the given key with type char
def hash_function_char_complex(x):
    return (37 * ord(x)) % table_size

# This function calculates the hash value of the given key with type string
def hash_function_str(x):
    res = 0
    for i in range(len(x)):
        res = (res + ord(x[i])) % table_size
    return res

# This function calculates the hash value of the given key with type string
def hash_function_str_complex(x):
    res = 0
    for i in range(len(x)):
        res = (res + 37 * ord(x[i]) * (i+1)) % table_size
    return res


# Functionality Testing


print("Table size:", table_size)

''' Expected Output:
Table size: 100003
'''

print("key", int(1e9+6), end='')
print(" has hash value", hash_function_int(int(1e9+6)))

print("key", int(1e9+6), end='')
print(" has hash value", hash_function_int_complex(int(1e9+6)))

print("key", int(1<<61), end='')
print(" has hash value", hash_function_long(1<<61))

print("key", int(1<<61), end='')
print(" has hash value", hash_function_long_complex(1<<61))

''' Expected Output:
key 1000000006 has hash value 70009
key 1000000006 has hash value 90258
key 2305843009213693952 has hash value 13994
key 2305843009213693952 has hash value 17763
'''

print("key", 'R', end='')
print(" has hash value", hash_function_char('R'))

print("key", 'R', end='')
print(" has hash value", hash_function_char_complex('R'))

print("key", "hashtables", end='')
print(" has hash value", hash_function_str("hashtables"))

print("key", "hashtables", end='')
print(" has hash value", hash_function_str_complex("hashtables"))

''' Expected Output:
key R has hash value 82
key R has hash value 3034
key hashtables has hash value 1055
key hashtables has hash value 15704
'''
