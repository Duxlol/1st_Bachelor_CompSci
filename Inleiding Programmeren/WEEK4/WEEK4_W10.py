from math import sqrt
def is_priem(x):
    i = 2
    while i <= sqrt(x):
        if x % i == 0:
            return False
        i +=1
    return True
def volgend_priemgetal(x):
    j=1
    while not is_priem(x + j):
        j += 1
    return x + j
def priemgetallen(n):
    primesList = []
    i = 2
    while len(primesList) < n:
        if is_priem(i):
            primesList.append(i)
            i += 1
        else:
            i += 1
    return primesList
def fibonacci(n):
    fibonacciSequence = [1, 1]
    if n == 1:
        return fibonacciSequence[:1]
    if n == 2:
        return fibonacciSequence[:2]

    if n > 2:
        for i in range(2, n):
            num = fibonacciSequence[-1] + fibonacciSequence[-2]
            fibonacciSequence.append(num)
        return fibonacciSequence
def priem_en_fib(n):
    s=set(priemgetallen(n))
    f=set(fibonacci(n))
    return (s & f)
print(priem_en_fib(2))
print(priem_en_fib(3))
print(priem_en_fib(4))
print(priem_en_fib(5))
print(priem_en_fib(6))