class MyStack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.stack = []
    def isEmpty(self):
        return len(self.stack) == 0

    def getTop(self):
        if self.isEmpty():
            return (None, False)
        return (self.stack[-1], True)

    def pop(self):
        if self.isEmpty():
            return (None, False)
        return (self.stack.pop(), True)

    def push(self, element):
        if len(self.stack) < self.capacity:
            self.stack.append(element)
            return True
        return False

    def save(self):
        return self.stack[:]

    def load(self, elements):
        self.stack = elements[:]

if __name__ == "__main__":
    s = MyStack(2)
    print(s.isEmpty())
    print(s.getTop()[1])
    print(s.pop()[1])
    print(s.push(2))
    print(s.push(4))
    print(s.push(1))
    print(s.isEmpty())
    print(s.pop()[0])
    s.push(5)
    print(s.save())

    s.load(['a','b','c'])
    print(s.save())
    print(s.pop()[0])
    print(s.save())
    print(s.getTop()[0])
    print(s.save())