def is_gesorteerd(lst):
    return lst == sorted(lst) or lst == sorted(lst, reverse=True)

print(is_gesorteerd([1, 2, 3, 4, 5]))  # True
print(is_gesorteerd([-1, -2, -3, -4, -5]))  # True
print(is_gesorteerd([5, -3, 8, 1, 2]))