class MyQueue:
    def __init__(self,capacity):
        self.capacity = capacity
        self.queue = []
    def isEmpty(self):
        if len(self.queue) == 0:
            return True
        return False
    def enqueue(self,value):
        if len(self.queue) < self.capacity:
            self.queue.append(value)
            return True
        return False
    def dequeue(self):
        if self.isEmpty():
            return None, False
        return self.queue.pop(0),True
    def getFront(self):
        if self.isEmpty():
            return None,False
        return self.queue[0],True
    def load(self,nodes):
        if len(nodes) <= self.capacity:
            self.queue = nodes
        else:
            return False
    def save(self):
        return self.queue