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
print(priemgetallen(30))