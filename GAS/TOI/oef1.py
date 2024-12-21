class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class MyStack:
    def __init__(self):
        self.top = None  # Points to the top node of the stack

    def isEmpty(self):
        return self.top is None

    def getTop(self):
        if self.isEmpty():
            return (None, False)
        return (self.top.value, True)

    def pop(self):
        if self.isEmpty():
            return (None, False)
        popped_value = self.top.value
        self.top = self.top.next
        return (popped_value, True)

    def push(self, element):
        new_node = Node(element)
        new_node.next = self.top
        self.top = new_node
        return True

    def save(self):
        def recurse(node):
            if node is None:
                return []
            return recurse(node.next) + [node.value]
        return recurse(self.top)

    def load(self, elements):
        self.top = None  # Reset the stack
        for elem in elements:
            self.push(elem)
