# zelf gemaakte dubbelgelinkte ketting van GAS Sem 1 | Thijs Van Schel

class DubbeleNode:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None


class LinkedChain:
    def __init__(self):
        self.head = None  # ptr nr eerste elm.
        self.size = 0  # tracker vn elm.

    def isEmpty(self):
        return self.head is None

    def getLength(self):
        return self.size

    def retrieve(self, index):
        if index < 1 or index > self.size or self.isEmpty():
            return (None, False)
        current = self.head
        for _ in range(index - 1):
            current = current.next
        return (current.value, True)

    def insert(self, index, value):
        if index < 1 or index > self.size + 1:
            return False
        new_node = DubbeleNode(value)

        # als leeg => eerst nieuwe node aanmaken
        if self.isEmpty():
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node

        elif index == 1:
            # vooraan inserten
            tail = self.head.prev
            new_node.next = self.head
            new_node.prev = tail
            tail.next = new_node
            self.head.prev = new_node
            self.head = new_node

        else:
            # op positie inserten
            current = self.head
            for _ in range(index - 2):
                current = current.next
            new_node.next = current.next
            new_node.prev = current
            current.next.prev = new_node
            current.next = new_node
        self.size += 1
        print("Werknemer is in de chain gezet.")
        return True

    def delete(self, index):
        if index < 1 or index > self.size or self.isEmpty():
            return False
        if self.size == 1:
            self.head = None

        elif index == 1:
            # verwijder eerste elm.
            tail = self.head.prev
            self.head = self.head.next
            self.head.prev = tail
            tail.next = self.head

        else:
            current = self.head
            for _ in range(index - 1):
                current = current.next
            current.prev.next = current.next
            current.next.prev = current.prev
        self.size -= 1
        return True

    def traverse(self):
        if self.isEmpty():
            return []
        result = []
        current = self.head
        for _ in range(self.size):
            result.append(current.value)
            current = current.next
        return result

    def save(self):
        return self.traverse()

    def load(self, elements):
        self.head = None
        self.size = 0
        for element in elements:
            self.insert(self.size + 1, element)