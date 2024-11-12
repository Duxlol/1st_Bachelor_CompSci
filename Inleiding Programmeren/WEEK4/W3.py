l = [1, 2, 5, 3, 2, 17, 5, 6, 7, 3, 2, 1, 9, 3]
def tel_getallen(l):
    i=0
    for i in range(len(l)):
        lol = l.count(i)
        i += 1
    print(f"{i}" + " " + f"{lol}")


print(tel_getallen(l))