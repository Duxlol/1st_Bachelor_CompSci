## CREATE DICE
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

## LOSE
def lose():
    total = create_dice()[2] | create_dice()[3] | create_dice()[12]
    return total
## WIN
def win():
    total = create_dice()[7] | create_dice()[11]
    return total

## ROLLS DICE
from random import randint
def roll_dice():
    random = (randint(1,6),randint(1,6))
    return random

## CHECK IF GAME ENDS
def game_ends(worp):
    if worp in win() or worp in lose():
        return True

    return False
print(game_ends((6,2)))