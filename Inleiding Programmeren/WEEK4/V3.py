l = ["s", "w", "h", "s", "h"]
def item_order(items):
    s = 0
    w = 0
    h = 0
    bestelling = []
    for i in range(len(items)):
        if items[i] == "s":
            s += 1
        elif items[i] == "w":
            w += 1
        elif items[i] == "h":
            h += 1
    bestelling.append(s)
    bestelling.append(h)
    bestelling.append(w)
    return bestelling

##############################################
def item_order2(items):
    s = items.count("s")
    h = items.count("h")
    w = items.count("w")
    return [s,h,w]
print(item_order2(l))


