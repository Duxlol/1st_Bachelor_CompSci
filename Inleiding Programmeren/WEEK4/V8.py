def create_dice():
    dice = []
    for i in range(13):
        s = set()
        dice.append(s)

    for i in range(1,7):
        for j in range(1,7):
            sum = i+j
            dice[sum].add((i,j))
    return dice
def lose():
    total = create_dice()[2] | create_dice()[3] | create_dice()[12]
    return total

def win():
    total = create_dice()[7] | create_dice()[11]
    return total
print(win)