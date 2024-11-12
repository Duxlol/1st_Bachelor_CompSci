from fontTools.merge.util import first

L = [10,12,3,4,5,1,22,5]
L2 = [10,12,3,4,5,1,22,5,7]
from math import floor,ceil
def splits(lst):
    firstHalf = []
    secondHalf= []
    total = firstHalf,secondHalf
    if len(lst) % 2 == 0:
        for i in range(len(lst)//2):
            firstHalf.append(lst[i])
        for i in range(len(lst)//2,len(lst)):
            secondHalf.append(lst[i])
    elif len(lst) % 2 != 0:
        for i in range(floor(len(lst)/2)):
            firstHalf.append(lst[i])
        for i in range(ceil(len(lst)/2),len(lst)):
            secondHalf.append(lst[i])
    formatted_output = f"([{','.join(map(str, firstHalf))}],[{','.join(map(str, secondHalf))}])"
    return formatted_output


l = [1, 3, 2, 7]
print(splits(l))
l = [5,1,3,4,3,2,7]
print(splits(l))
l = [1,2,3]
print(splits(l))