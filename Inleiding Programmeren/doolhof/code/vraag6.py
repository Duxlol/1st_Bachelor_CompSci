# Tel het aantal stappen om het doolhof op te lossen

from doolhof import *

# Right-hand rule - count steps
laadDoolhof("doolhof4.txt")

stepsRHR=0
while not foundExit():
    stepsRHR=stepsRHR+1
    if freeRight(): # right is free
        turnRight()
        goForward()
    elif freeForward(): # not right, but forward is free
        goForward()
    elif freeLeft():  # not right, not forward, but left free
        turnLeft()
        goForward()
    else: # neither right, nor forward, nor left are free
        turnLeft()
        turnLeft()
        goForward()

laadDoolhof("doolhof4.txt") # reset the maze by reloading
# Lefthand rule - count steps
stepsLHR = 0
# your code goes here
while not foundExit():
    stepsLHR=stepsLHR+1
    if freeLeft():  # not right, not forward, but left free
        turnLeft()
        goForward()
    elif freeForward(): # not right, but forward is free
        goForward()
    elif freeRight(): # right is free
        turnRight()
        goForward()
    else: # neither right, nor forward, nor left are free
        turnLeft()
        turnLeft()
        goForward()

# Decide which one is larger and print output
if stepsRHR > stepsLHR:
    print("RHR requires the highest amount of steps", stepsRHR)
elif stepsRHR == stepsLHR:
    print("The same amount of steps are required \n", "RHR: ", stepsRHR, "LHR: ", stepsLHR)
elif stepsRHR < stepsLHR:
    print("LHR requires the highest amount of steps", stepsLHR)



# laat deze regel staan zodat het venster blijft openstaan
turtle.done()

