l3 = ['Ten', 'Twenty', 'Thirty']
l4= [10, 20, 30]
def list2dict(l1,l2):
    i=0
    dctry = dict()
    for i in range(len(l1)):
        dctry[l1[i]] = l2[i]
        i += 1
    return dctry
print(list2dict(l3,l4))