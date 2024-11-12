# Tel het aantal stappen om het doolhof op te lossen
# Voeg code toe om ook het aantal linkse en rechtse bochten
# te tellen 

from doolhof import *

# Right-hand rule
laadDoolhof("doolhof4.txt")
steps=0
RHS = 0
LHS = 0
while not foundExit():
    steps=steps+1
    if freeRight(): # right is free
        RHS=RHS+1
        turnRight()
        goForward()
    elif freeForward(): # not right, but forward is free
        goForward()
    elif freeLeft(): # not right, not forward, but left free
        LHS=LHS+1
        turnLeft()
        goForward()
    else: # neither right, nor forward, nor left are free
        LHS = LHS+2
        turnLeft()
        turnLeft()
        goForward()

print("Aantal stappen:",steps)
print("Aantal x links:", LHS)
print("Aantal x rechts:", RHS)




# laat deze regel staan zodat het venster blijft openstaan
turtle.done()