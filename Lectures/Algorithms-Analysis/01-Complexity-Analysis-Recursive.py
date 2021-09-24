def function_1(n):
    if n == 0:
        return
    function_1(n//2)
    function_1(n//2)
    function_1(n//2)
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            j += 1
        i += 1

def function_2(n):
    if n == 0:
        return
    function_2(n//2)
    function_2(n//2)
    function_2(n//2)
    function_2(n//2)
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            j += 1
        i += 1

def function_3(n):
    if n == 0:
        return
    function_3(n//2)
    i = 1
    while i * i <= n:
        j = 1
        while j <= n:
            j *= 2
        i += 1

def function_4(n):
    if n == 0:
        return
    j = 1
    while j <= 16:
        function_4(n//4)
        j += 1
    i = 1
    while i <= n:
        i += 1

def function_5(n):
    if n == 0:
        return
    function_5(n//2)
    function_5(n//2)
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            j *= 2
        i += 1

def function_6(n):
    if n == 0:
        return
    function_6(n//4)
    function_6(n//4)
    i = 1
    while i * i <= n:
        i += 1

def function_7(n):
    if n == 0:
        return
    function_7(n//2)
    i = 1
    while i <= 100:
        i += 1

def function_8(n):
    if n == 0:
        return
    function_8(n//2)
    function_8(n//2)
    function_8(n//2)
    i = 1
    while i <= n:
        i += 1

def function_9(n):
    if n == 0:
        return
    function_9(n//3)
    function_9(n//3)
    function_9(n//3)
    i = 1
    while i * i <= n:
        i += 1

def function_10(n):
    if n == 0:
        return
    function_10(n//2)
    function_10(n//2)
    function_10(n//2)
    function_10(n//2)
    i = 1
    while i <= 3*n:
        i += 1

def function_11(n):
    if n == 0:
        return
    function_11(n//4)
    function_11(n//4)
    function_11(n//4)
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            j *= 2
        i += 1

def function_12(n):
    if n == 0:
        return
    function_12(n//3)
    function_12(n//3)
    function_12(n//3)
    i = 1
    while i <= n // 2:
        i += 1

def function_13(n):
    if n == 0:
        return
    t = 1
    while t <= 6:
        function_13(n//3)
        t += 1
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            k = 1
            while k <= n:
                k *= 2
            j += 1
        i += 1

def function_14(n):
    if n == 0:
        return
    t = 1
    while t <= 64:
        function_14(n//8)
        t += 1
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            k = 1
            while k <= n:
                k *= 2
            j += 1
        i += 1

def function_15(n):
    if n == 0:
        return
    t = 1
    while t <= 7:
        function_15(n//3)
        t += 1
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            j += 1
        i += 1

def function_16(n):
    if n == 0:
        return
    function_16(n//2)
    function_16(n//2)
    function_16(n//2)
    function_16(n//2)
    i = 1
    while i <= n:
        i *= 2

def function_17(n):
    if n == 0:
        return
    function_17(n//2)
    i = 1
    while i <= 7*n:
        i += 1

def function_18(n):
    if n == 0:
        return
    function_18(n//2)
    i = 1
    while i <= n:
        j = 1
        while j <= n:
            j *= 2
        i *= 2


function_1(10)
function_1(100)
function_2(10)
function_2(100)
function_3(10)
function_3(100)
function_4(10)
function_4(100)
function_5(10)
function_5(100)
function_6(10)
function_6(100)
function_7(10)
function_7(100)
function_8(10)
function_8(100)
function_9(10)
function_9(100)
function_10(10)
function_10(100)
function_11(10)
function_11(100)
function_12(10)
function_12(100)
function_13(10)
function_13(100)
function_14(10)
function_14(100)
function_15(10)
function_15(100)
function_16(10)
function_16(100)
function_17(10)
function_17(100)
function_18(10)
function_18(100)
