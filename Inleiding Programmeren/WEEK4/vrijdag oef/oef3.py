def item_order(items):
    s = items.count('s')
    h = items.count('h')
    w = items.count('w')
    return [s,h,w]

db1 = {}
def place_order(db,email,order):
    db[email] = item_order(order)
    return db

def print_previous_order(db,email):
    if not db[email]:
        print("Je hebt nog geen bestelling geplaatst.")
    else:
        print(f"Je bestelde {db[email][0]} salade(s).\nJe bestelde {db[email][1]} hamburger(s).\nJe bestelde {db[email][2]} water(s).")

place_order(db1,"jefke@gmail.com",["s", "w", "h", "s", "h"])
print_previous_order(db1,"jefke@gmail.com")