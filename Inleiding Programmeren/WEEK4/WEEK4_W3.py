l = [1, 2, 5, 3, 2, 17, 5, 6, 7, 3, 2, 1, 9, 3]
def tel_getallen(l):
    for i in range(max(l)+1):
        print(str(i),str(l.count(i)))

l = [1, 2, 5, 3, 2, 7, 5, 6, 17, 3, 2, 1, 9, 3]
tel_getallen(l)
l = [1, 1, 1, 1, 1]
tel_getallen(l)