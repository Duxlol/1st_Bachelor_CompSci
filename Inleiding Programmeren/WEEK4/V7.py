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
print(create_dice()[7])