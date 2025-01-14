from math import *
def splits(lst):
    lengte = len(lst) // 2
    if (len(lst)%2 != 0):
        return ((lst[:lengte]),(lst[ceil((len(lst))/2):len(lst)]))
    else:
        return ((lst[:lengte]), (lst[lengte:]))
lst = [1,2,3,4,5,6,7,8,9]
lst2 = [1,2,3,4,5,6,7,8]
print(splits(lst))
print(splits(lst2))