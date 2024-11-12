from math import sqrt
def is_priem(x):
    i = 2
    while i <= sqrt(x):
        if x % i == 0:
            return False
        i +=1
    return True