# hoeveel groepjes van 2 spaties voor de nummers
# 4,3,2,1,0
#
#
#

def piramide(n):
    output = ""
    breedte = 1
    leeg = n - 1
    for i in range(n):
        output += ' '*leeg
    for j in range(1, breedte+1):
        output += str(j) + " "
    output += "\n"
    breedte += 1
    return output
print(piramide(5))
