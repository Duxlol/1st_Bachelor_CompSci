from alice_book import book
woorden = book.split()

tmp = ["aap","banaan","aap","hond","aap","aap"]
def tel_woorden(woorden):
    dictry=dict()
    for i in woorden:
        amount = woorden.count(i)
        dictry[i] = amount
    return dictry
print(tel_woorden(woorden))