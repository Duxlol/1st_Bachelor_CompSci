def item_order(items):
    s = items.count("s")
    h = items.count("h")
    w = items.count("w")
    return [s,h,w]

def place_order(db,email,order):
    db[email] = item_order(order)
    return db

def print_previous_order(db, email):
    if email in db:
        print(f"Je bestelde {db[email][0]} salade(s).\nJe bestelde {db[email][1]} hamburger(s).\nJe bestelde {db[email][2]} water(s).")
    else:
        print("Je hebt nog geen bestellingen geplaatst.")
db = {}
print_previous_order(db,"jefke@gmail.com")
place_order(db,"jefke@gmail.com",["s", "w", "h", "s", "h"])
place_order(db,"mieke@gmail.com",["w", "w", "h", "s", "h"])
print_previous_order(db,"jefke@gmail.com")
print_previous_order(db,"mieke@gmail.com")
