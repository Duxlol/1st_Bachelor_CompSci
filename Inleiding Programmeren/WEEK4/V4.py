def item_order(items):
    s = items.count("s")
    h = items.count("h")
    w = items.count("w")
    return [s,h,w]
data = dict()
def place_order(db,email,order):
    db[email] = item_order(order)
    return db

print(place_order(data,"jefke@gmail.com",["s", "w", "h", "s", "h"]))