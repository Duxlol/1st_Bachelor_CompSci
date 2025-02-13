# zelf gemaakte queue van GAS Sem 1 | Thijs Van Schel

class MyQueue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front = 0
        self.rear = -1
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def isFull(self):
        return self.size == self.capacity

    def enqueue(self, value):
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.capacity
        self.queue[self.rear] = value
        self.size += 1
        return True

    def dequeue(self):
        if self.isEmpty():
            return None, False
        value = self.queue[self.front]
        self.queue[self.front] = None
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return value, True

    def getFront(self):
        if self.isEmpty():
            return None, False
        return self.queue[self.front], True

    def load(self, nodes):
        if len(nodes) > self.capacity:
            return False
        self.queue = [None] * self.capacity
        for i in range(len(nodes)):
            #omgekeerde volg. door testcode
            self.queue[i] = nodes[len(nodes) - i - 1]
        self.front = 0
        self.rear = len(nodes) - 1
        self.size = len(nodes)
        return True

    def save(self):
        result = []
        for i in range(self.size):
            # omgekeerde volg.
            result.append(self.queue[(self.rear - i) % self.capacity])
        return result