lst = [5,2,3,2,3,2,5,3,7,5]
def minimum_elements(integers):
    smallest = integers[0]
    for i in range(len(integers)):
        if integers[i] < smallest:
            smallest = integers[i]
        i += 1
    return (smallest,integers.count(smallest))

print(minimum_elements(lst))