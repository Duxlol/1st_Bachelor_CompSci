lijst = ['hond','kat','kat','dier', 'hond']
def tel_woorden(woorden):
    dictry=dict()
    for i in woorden:
            amount = woorden.count(i)
            dictry[i] = amount
    return dictry
def print_frequenties(dct):
     for i in dct:
         print(i + " " + str(dct[i]))

print_frequenties(tel_woorden(lijst))