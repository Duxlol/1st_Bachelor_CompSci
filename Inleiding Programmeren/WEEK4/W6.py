l3 = ['Ten', 'Twenty', 'Thirty']
l4= [10, 20, 30]
def list2dict(l1,l2):
    i=0
    dctry = dict()
    try:
        for i in range(len(l1)):
            dctry[l1[i]] = l2[i]
            i += 1
    except:
        print("")
    return dctry
print(list2dict(['Ten', 'Twenty', 'Thirty'],[10, 20, 30]))
print(list2dict(['Ten', 'Twenty', 'Thirty'],[10, 20]))
print(list2dict(['Ten', 'Ten', 'Thirty'],[10, 20]))
print(list2dict([1,2,3,4],[5,6,7,8]))