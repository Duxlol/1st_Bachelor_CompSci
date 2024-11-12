def fibonacci(n):
    fibonacciSequence = [1, 1]
    if n == 1:
        return str(fibonacciSequence[:1]).replace(' ', '')
    if n == 2:
        return str(fibonacciSequence[:2]).replace(' ', '')

    if n > 2:
        for i in range(2, n):
            num = fibonacciSequence[-1] + fibonacciSequence[-2]
            fibonacciSequence.append(num)
        return str(fibonacciSequence).replace(' ', '')

print(fibonacci(2))
print(fibonacci(3))
print(fibonacci(4))
print(fibonacci(5))
print(fibonacci(6))
print(fibonacci(7))
