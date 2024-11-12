def fibonacci(n):
    fibonacciSequence = [1, 1]
    if n == 1:
        return fibonacciSequence[0]
    if n == 2:
        return fibonacciSequence[1]

    if n > 2:
        for i in range(2, n):
            num = fibonacciSequence[-1] + fibonacciSequence[-2]
            fibonacciSequence.append(num)
        return fibonacciSequence


