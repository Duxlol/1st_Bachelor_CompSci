class MyQueue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None] * capacity  # Fixed-size list
        self.front = 0  # Points to the front of the queue
        self.rear = -1  # Points to the last element
        self.size = 0  # Tracks the number of elements in the queue

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
        self.queue[self.front] = None  # Clear the dequeued spot (optional)
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
        self.queue = [None] * self.capacity  # Reset the queue
        for i in range(len(nodes)):
            self.queue[i] = nodes[len(nodes) - i - 1]  # Reverse order
        self.front = 0
        self.rear = len(nodes) - 1
        self.size = len(nodes)
        return True

    def save(self):
        result = []
        for i in range(self.size):
            result.append(self.queue[(self.rear - i) % self.capacity])  # Reverse order
        return result


if __name__ == "__main__":
    q = MyQueue(10)
    print(q.isEmpty())
    print(q.getFront()[1])
    print(q.dequeue()[1])
    print(q.enqueue(2))
    print(q.enqueue(4))
    print(q.isEmpty())
    print(q.dequeue()[0])
    q.enqueue(5)
    print(q.save())

    q.load(['a', 'b', 'c'])
    print(q.save())
    print(q.dequeue()[0])
    print(q.save())
    print(q.getFront()[0])
    print(q.save())