def calc_sum(n):
    res = 0
    while n > 0:
        res += n
        n -= 1
    return res

def power(b, e):
    res = 1
    while e > 0:
        res *= b
        e -= 1
    return res

def factorial(n):
    res = 1
    while n > 0:
        res *= n
        n -= 1
    return res

def fib(x, y, n):
    while n > 0:
        print(x + y, end=' ')
        x, y = y, x+y
        n -= 1

def is_prime(i, n):
    while i < n:
        if n % i == 0:
            return False
        i += 1
    return True

n = 10
arr = [7, 4, -5, 2, -10, 3, -12, -17, 6, 13]

def print_evens(i, n):
    while i < n:
        if arr[i] % 2 == 0:
            print(arr[i], end=' ')
        i += 1

def print_odds(i, n):
    while i < n:
        if arr[i] % 2 != 0:
            print(arr[i], end=' ')
        i += 1

def print_array_reverse(i):
    while i >= 0:
        print(arr[i], end=' ')
        i -= 1

def print_array(i):
    while i < n:
        print(arr[i], end=' ')
        i += 1

def reverse_array(i, j):
    while i < j:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1

def print_positive(i, n):
    while i < n:
        if arr[i] > 0:
            print(arr[i], end=' ')
        i += 1

def print_negative(i, n):
    while i < n:
        if arr[i] < 0:
            print(arr[i], end=' ')
        i += 1

def count_positive(i, n):
    res = 0
    while i < n:
        res += int(arr[i] > 0)
        i += 1
    return res

def count_negative(i, n):
    res = 0
    while i < n:
        res += int(arr[i] < 0)
        i += 1
    return res

def count_even(i, n):
    res = 0
    while i < n:
        res += int(arr[i] % 2 == 0)
        i += 1
    return res

def count_odd(i, n):
    res = 0
    while i < n:
        res += int(arr[i] % 2 != 0)
        i += 1
    return res

def find_max_array(i, n):
    res = -int(2e9)
    while i < n:
        res = max(res, arr[i])
        i += 1
    return res

def find_min_array(i, n):
    res = int(2e9)
    while i < n:
        res = min(res, arr[i])
        i += 1
    return res

def find_item_array(i, n, k):
    while i < n:
        if arr[i] == k:
            return True
        i += 1
    return False


s = "abCdeFghIjkL"

def print_str(i):
    while i < len(s):
        print(s[i], end=' ')
        i += 1

def print_str_reverse(i):
    while i >= 0:
        print(s[i], end=' ')
        i -= 1

def reverse_str(i, j):
    while i < j:
        s[i], s[j] = s[j], s[i]
        i += 1
        j -= 1

def print_smalls(i):
    while i < len(s):
        if 'a' <= s[i] and s[i] <= 'z':
            print(s[i], end=' ')
        i += 1

def print_capitals(i):
    while i < len(s):
        if 'A' <= s[i] and s[i] <= 'Z':
            print(s[i], end=' ')
        i += 1

def count_smalls(i):
    res = 0
    while i < len(s):
        if 'a' <= s[i] and s[i] <= 'z':
            res += 1
        i += 1
    return res

def count_capitals(i):
    res = 0
    while i < len(s):
        if 'A' <= s[i] and s[i] <= 'Z':
            res += 1
        i += 1
    return res

def find_max_str(i):
    res = s[n-1]
    while i < n-1:
        res = max(res, s[i])
        i += 1
    return res

def find_min_str(i):
    res = s[n-1]
    while i < n-1:
        res = min(res, s[i])
        i += 1
    return res

def find_item_str(i, k):
    while i < n:
        if s[i] == k:
            return True
        i += 1
    return False


# Functionality Testing 

print("sum 1 to 4  :", calc_sum(4))
print("power 2^10  :", power(2, 10))
print("factorial 6 :", factorial(6))
print("fibonacci 6 : ")
fib(0, 1, 6)
print()
print("15 is prime :", is_prime(2, 15))
print("17 is prime :", is_prime(2, 17))
print("----------------------------------------------------")

''' Expected Output:
sum 1 to 4  : 10
power 2^10  : 1024
factorial 6 : 720
fibonacci 6 : 1 2 3 5 8 13 
15 is prime : 0
17 is prime : 1
----------------------------------------------------
'''

print("array items : ")
print_array(0)
print()
print_array_reverse(n-1)
print()
print("array reverstr ... ")
reverse_array(0, n-1)
print("array items : ")
print_array(0)
print()
print_array_reverse(n-1)
print()
print("----------------------------------------------------")

''' Expected Output:
array items : 
7 4 -5 2 -10 3 -12 -17 6 13 
13 6 -17 -12 3 -10 2 -5 4 7 
array reverstr ... 
array items : 
13 6 -17 -12 3 -10 2 -5 4 7 
7 4 -5 2 -10 3 -12 -17 6 13 
----------------------------------------------------
'''

print("count evens :", count_even(0, n))
print("count odds  :", count_odd(0, n))
print("array even items : ")
print_evens(0, n)
print()
print("array odd items  : ")
print_odds(0, n)
print()
print("----------------------------------------------------")

''' Expected Output:
count evens : 5
count odds  : 5
array even items : 6 -12 -10 2 4 
array odd items  : 13 -17 3 -5 7 
----------------------------------------------------
'''

print("count positive :", count_positive(0, n))
print("count negative :", count_negative(0, n))
print("array positive items : ")
print_positive(0, n)
print()
print("array negative items : ")
print_negative(0, n)
print()
print("----------------------------------------------------")

''' Expected Output:
count positive : 6
count negative : 4
array positive items : 13 6 3 2 4 7 
array negative items : -17 -12 -10 -5 
----------------------------------------------------
'''

print("find max array :", find_max_array(0, n))
print("find min array :", find_min_array(0, n))
print("find 4 in array  :", find_item_array(0, n, 4))
print("find 5 in array  :", find_item_array(0, n, 5))
print("find -4 in array :", find_item_array(0, n, -4))
print("find -5 in array :", find_item_array(0, n, -5))
print("----------------------------------------------------")

''' Expected Output:
find max array : 13
find min array : -17
find 4 in array  : 1
find 5 in array  : 0
find -4 in array : 0
find -5 in array : 1
----------------------------------------------------
'''

print("str items : ")
print_str(0)
print()
print_str_reverse(n-1)
print()
print("str reverstr ... ")
s = list(s)
reverse_str(0, n-1)
s = ''.join(s)
print("str items : ")
print_str(0)
print()
print_str_reverse(n-1)
print()
print("----------------------------------------------------")

''' Expected Output:
str items : 
a b C d e F g h I j k L 
j I h g F e d C b a 
str reverstr ... 
str items : 
j I h g F e d C b a k L 
a b C d e F g h I j 
----------------------------------------------------
'''

print("count smalls   :", count_smalls(0))
print("count capitals :", count_capitals(0))
print("str small items   : ")
print_smalls(0)
print()
print("str capital items : ")
print_capitals(0)
print()
print("----------------------------------------------------")

''' Expected Output:
count smalls   : 8
count capitals : 4
str small items   : j h g e d b a k 
str capital items : I F C L 
----------------------------------------------------
'''

print("find max str : " , find_max_str(0))
print("find max str : " , find_min_str(0))
print("find a in str :", find_item_str(0, 'a'))
print("find f in str :", find_item_str(0, 'f'))
print("find A in str :", find_item_str(0, 'A'))
print("find F in str :", find_item_str(0, 'F'))
print("----------------------------------------------------")

''' Expected Output:
find max str : j
find max str : C
find a in str : 1
find f in str : 0
find A in str : 0
find F in str : 1
----------------------------------------------------
'''
