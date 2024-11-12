from math import sqrt
def is_priem(x):
    y=2
    while y<x:
        if (x%y)==0:
            return False
        else:
            y= y+1
    return True
def volgend_priemgetal(x):
    volgendegetal= x+1
    while not is_priem(volgendegetal):
        volgendegetal+=1
    return volgendegetal
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

def priem_of_fib(n):
    s=set()
    for i in range(n):
        s.update(priemgetallen(n))
        s.update(fibonacci(n))
    return str(s).replace(' ', '')
print(priem_of_fib(2))
print(priem_of_fib(3))
print(priem_of_fib(4))
print(priem_of_fib(5))
print(priem_of_fib(6))
print(priem_of_fib(7))