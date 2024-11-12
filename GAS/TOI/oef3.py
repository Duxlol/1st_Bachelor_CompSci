class Node:
    def __init__(self,value=None):
        self.value = value
        self.next = None
class MyQueue:
    def __init__(self,capacity):
        self.front = None
        self.back = None
    def isEmpty(self):
        if self.front:
            return (None, False)
        return (None, True)



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