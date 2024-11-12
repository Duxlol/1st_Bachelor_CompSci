class MyQueue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = []
    def isEmpty(self):
        return len(self.queue) == 0

    def enqueue(self, value):
        if len(self.queue) < self.capacity:
            self.queue.append(value)
            return True
        return False

    def dequeue(self):
        if self.isEmpty():
            return None, False
        return self.queue.pop(0), True

    def getFront(self):
        if self.isEmpty():
            return None, False
        return self.queue[0], True

    def load(self, nodes):
        self.queue = []
        if len(nodes) <= self.capacity:
            self.queue = nodes[::-1]
            return True
        return False

    def save(self):
        return self.queue[::-1]