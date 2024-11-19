class MyStack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.stack = [None] * capacity  # Initialize stack with None values
        self.top = -1  # Stack is initially empty

    def isEmpty(self):
        return self.top == -1

    def getTop(self):
        if self.isEmpty():
            return (None, False)
        return (self.stack[self.top], True)

    def pop(self):
        if self.isEmpty():
            return (None, False)
        popped = self.stack[self.top]
        self.stack[self.top] = None  # Clear the popped element
        self.top -= 1
        return (popped, True)

    def push(self, element):
        if self.top == self.capacity - 1:  # Stack is full, so increase capacity by 1
            self.capacity += 1
            self.stack.append(None)  # Add space for the new element
        self.top += 1
        self.stack[self.top] = element
        return True

    def save(self):
        # Return only non-None elements
        return [x for x in self.stack if x is not None]

    def load(self, elements):
        for elem in elements:
            if self.top == self.capacity - 1:  # Stack is full, so increase capacity by 1
                self.capacity += 1
                self.stack.append(None)  # Add space for the new element
            self.top += 1
            self.stack[self.top] = elem
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