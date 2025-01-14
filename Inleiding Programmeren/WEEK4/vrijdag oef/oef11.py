lst1 = [744,5243,243,22, 32435,4864,324,22,22,22]
def minimum_elements(lst):
    tmp = lst[0]
    for i in range(len(lst)):
        if (lst[i] < tmp):
            tmp = lst[i]
    return (tmp, lst.count(tmp))

print(minimum_elements(lst1))