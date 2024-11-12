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

print(volgend_priemgetal())