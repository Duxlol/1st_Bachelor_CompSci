def is_prime(n):
    if n <= 0:
        return None

    for i in range(n-1, 2, -1):
        if n % i == 0 and n != 1:
            return False

    return True

print(is_prime(71))
print(is_prime(2))