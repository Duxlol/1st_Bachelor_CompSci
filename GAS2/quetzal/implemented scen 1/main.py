time = 0
import Werknemer
import MyStack
import MyDoublyLinkedChain
import MyQueue
import Bestelling
from MyBinarySearchTree import BST, createTreeItem

bst = BST()
stack = MyStack.MyStack()
chain = MyDoublyLinkedChain.LinkedChain()
queue = MyQueue.MyQueue(10)  # Queue capacity set to 10

# 1
werknemerA = Werknemer.Werknemer("A", "voornaamA", "achternaamA", 10)
chain.insert(1, werknemerA)
print("Werknemer A gemaakt en toegevoegd aan chain")

# 2
stack.push(werknemerA)
print("Werknemer A toegevoegd aan stack")

# 3
werknemerB = Werknemer.Werknemer("B", "voornaamB", "achternaamB", 3)
print("Werknemer B gemaakt en toegevoegd aan chain")
chain.insert(2, werknemerB)

# 4
stack.push(werknemerB)
print("Werknemer B toegevoegd aan stack")

# 5
bestelling1 = Bestelling.Bestelling(1, "gebruiker1", 0, 5)
print("Bestelling 1 gemaakt")

# 6
queue.enqueue(bestelling1)
print("Bestelling 1 toegevoegd aan queue")

# 7
bestelling2 = Bestelling.Bestelling(2, "gebruiker2", 1, 8)
print("Bestelling 2 gemaakt")

# 8
queue.enqueue(bestelling2)
print("Bestelling 2 toegevoegd aan queue")

# 9
time = 2
print(f"\nTijd is nu {time}")

# 10
bestelling, success = queue.dequeue()
if success:
    print(f"Bestelling {bestelling.bestelling_id} uit queue gehaald")

    # 11
    werknemer, success_w = stack.pop()
    if success_w:
        print(f"Werknemer {werknemer.werknemer_id} uit stack gehaald")

        # 12
        werknemer.assign_bestelling(bestelling)

# 13
bestelling2, success2 = queue.dequeue()
if success2:
    print(f"Bestelling {bestelling2.bestelling_id} uit queue gehaald")

    # 14
    werknemer2, success_w2 = stack.pop()
    if success_w2:
        print(f"Werknemer {werknemer2.werknemer_id} uit stack gehaald")

        # 15
        werknemer2.assign_bestelling(bestelling2)

# 16
time += 1
print(f"\nTijd is nu {time}")

# 17
workers = chain.traverse()
for worker in workers:
    if worker.current_bestelling:
        worker.overige_credits -= worker.credits
        if worker.overige_credits <= 0:
            print(f"Werknemer {worker.werknemer_id} heeft bestelling {worker.current_bestelling.bestelling_id} voltooid.")

            tree_item = createTreeItem(worker.current_bestelling.bestelling_id, worker.current_bestelling)
            bst.searchTreeInsert(tree_item)
            print(f"Bestelling {worker.current_bestelling.bestelling_id} toegevoegd aan de BST")
            stack.push(worker)
            print(f"Werknemer {worker.werknemer_id} terug op stack gezet")
            worker.current_bestelling = None
        else:
            print(f"Werknemer {worker.werknemer_id} heeft nog {worker.overige_credits} credits")

# 19
time += 1
print(f"\nTijd is nu {time}")

# 20
print("laden van elke werknemers' workload")
for worker in workers:
    if worker.current_bestelling:
        worker.overige_credits -= worker.credits
        if worker.overige_credits <= 0:
            print(f"Werknemer {worker.werknemer_id} heeft bestelling {worker.current_bestelling.bestelling_id} afgemaaklkt")
            stack.push(worker)
            print(f"Werknemer {worker.werknemer_id} terug op stack gezet")
            worker.current_bestelling = None
        else:
            print(f"Werknemer {worker.werknemer_id} heeft nog {worker.overige_credits} credits over")