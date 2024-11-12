zeef = []
for i in range(121):
    zeef.append(i)

for i in range(2,121):
    if zeef[i] != "rood":
        print(zeef[i], "is een priemgetal")
        for j in range(2*i,121,i):
            zeef[j] = "rood"
