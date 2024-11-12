lijst = ['hond','kat','kat','dier', 'hond']
def tel_woorden(woorden):
    dictry=dict()
    for i in woorden:
        amount = woorden.count(i)
        dictry[i] = amount
    return dictry
print(tel_woorden(['dit','is','een','korte','test']))