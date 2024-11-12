class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None

class MyStack:
    def __init__(self):
        self.top = None

    def isEmpty(self):
        return self.top is None

    def getTop(self):
        if self.top is None:
            return (False, None)
        else:
            return (True, self.top.value)

    def pop(self):
        if self.top is None:
            return (False, None)
        else:
            popped_value = self.top.value
            self.top = self.top.next
            return (True, popped_value)

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.top
        self.top = new_node
        return True

    def save(self):
        stack_list = []
        current = self.top
        while current is not None:
            stack_list.append(current.value)
            current = current.next
        return stack_list

    def load(self, lst):
        self.top = None
        for item in reversed(lst):
            self.push(item)

if __name__ == "__main__":
    s = MyStack()
    print(s.isEmpty())
    print(s.getTop()[1])
    print(s.pop()[1])
    print(s.push(2))
    print(s.push(4))
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