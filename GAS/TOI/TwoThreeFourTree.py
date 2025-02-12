class Node:
    def __init__(self):
        self.keys = []  # Keys in the node
        self.children = []  # Children nodes

    def is_leaf(self):
        return len(self.children) == 0

    def is_full(self):
        return len(self.keys) == 3


class TwoThreeFourTree:
    def __init__(self):
        self.root = Node()

    def isEmpty(self):
        return len(self.root.keys) == 0

    def split_node(self, parent, child, index):
        """Split a 4-node into two 2-nodes and push the middle key up."""
        middle_key = child.keys[1]
        left_child = Node()
        right_child = Node()

        # Distribute keys and children
        left_child.keys = child.keys[:1]
        right_child.keys = child.keys[2:]

        if not child.is_leaf():
            left_child.children = child.children[:2]
            right_child.children = child.children[2:]

        # Insert middle_key to the parent
        parent.keys.insert(index, middle_key)
        parent.children[index] = left_child
        parent.children.insert(index + 1, right_child)

    def insertItem(self, key):
        root = self.root

        # If root is full, split it
        if root.is_full():
            new_root = Node()
            new_root.children.append(self.root)
            self.split_node(new_root, self.root, 0)
            self.root = new_root

        # Insert key into non-full node
        self._insert_non_full(self.root, key)
        return True

    def _insert_non_full(self, node, key):
        if node.is_leaf():
            # Insert key into the correct position in the leaf
            index = 0
            while index < len(node.keys) and key > node.keys[index]:
                index += 1
            node.keys.insert(index, key)
        else:
            # Find the child to insert the key into
            index = 0
            while index < len(node.keys) and key > node.keys[index]:
                index += 1

            # If the child is full, split it
            if node.children[index].is_full():
                self.split_node(node, node.children[index], index)
                if key > node.keys[index]:
                    index += 1

            # Recursively insert into the appropriate child
            self._insert_non_full(node.children[index], key)

    def retrieveItem(self, key):
        node, found = self._find(self.root, key)
        if found:
            return True, key
        return False, None

    def _find(self, node, key):
        if node is None:
            return None, False

        index = 0
        while index < len(node.keys) and key > node.keys[index]:
            index += 1

        if index < len(node.keys) and key == node.keys[index]:
            return node, True

        if node.is_leaf():
            return None, False

        return self._find(node.children[index], key)

    def inorderTraverse(self, func):
        """Perform in-order traversal of the tree."""
        self._inorder(self.root, func)

    def _inorder(self, node, func):
        for i in range(len(node.keys)):
            if not node.is_leaf():
                self._inorder(node.children[i], func)
            func(node.keys[i])

        if not node.is_leaf():
            self._inorder(node.children[-1], func)

    def save(self):
        """Save the current tree structure as a dictionary."""
        return self._save_node(self.root)

    def _save_node(self, node):
        result = {"root": node.keys}
        if not node.is_leaf():
            result["children"] = [self._save_node(child) for child in node.children]
        return result

    def load(self, data):
        """Load a tree structure from a dictionary."""
        self.root = self._load_node(data)

    def _load_node(self, data):
        node = Node()
        node.keys = data["root"]
        if "children" in data:
            node.children = [self._load_node(child) for child in data["children"]]
        return node

    def deleteItem(self, key):
        if not self.root.keys:
            return False  # Tree is empty
        result = self._delete(self.root, key)
        if len(self.root.keys) == 0 and not self.root.is_leaf():
            self.root = self.root.children[0]  # Update root if it's empty
        return result

    def _delete(self, node, key):
        index = 0

        # Find the key or determine child index
        while index < len(node.keys) and key > node.keys[index]:
            index += 1

        # Case 1: Key is in the current node
        if index < len(node.keys) and node.keys[index] == key:
            if node.is_leaf():
                # Case 1a: Remove key from leaf
                node.keys.pop(index)
            else:
                # Case 1b: Key is in an internal node
                if len(node.children[index].keys) > 1:
                    # Use predecessor
                    predecessor = self._get_predecessor(node, index)
                    node.keys[index] = predecessor
                    self._delete(node.children[index], predecessor)
                elif len(node.children[index + 1].keys) > 1:
                    # Use successor
                    successor = self._get_successor(node, index)
                    node.keys[index] = successor
                    self._delete(node.children[index + 1], successor)
                else:
                    # Merge children and delete
                    self._merge_children(node, index)
                    self._delete(node.children[index], key)
            return True

        # Case 2: Key is not in the current node (leaf or internal)
        if node.is_leaf():
            return False  # Key not found

        child = node.children[index]

        # Case 3: Fix underflow if child is a 2-node
        if len(child.keys) == 1:
            self._fix_underflow(node, index)

        # Recalculate the child index if the structure changes
        if index < len(node.keys) and key > node.keys[index]:
            index += 1

        return self._delete(node.children[index], key)

    def _get_successor(self, node, index):
        # Find the smallest key in the right subtree
        child = node.children[index + 1]
        while not child.is_leaf():
            child = child.children[0]
        return child.keys[0]

    def _merge_children(self, parent, index):
        # Merge a child with its sibling and a parent key
        child = parent.children[index]
        sibling = parent.children[index + 1]
        child.keys.append(parent.keys.pop(index))
        child.keys.extend(sibling.keys)
        if not sibling.is_leaf():
            child.children.extend(sibling.children)
        parent.children.pop(index + 1)

    def _get_predecessor(self, node, index):
        child = node.children[index]
        while not child.is_leaf():
            child = child.children[-1]
        return child.keys[-1]

    def _fix_underflow(self, parent, index):
        child = parent.children[index]

        # Case 1: Borrow from the left sibling
        if index > 0 and len(parent.children[index - 1].keys) > 1:
            left_sibling = parent.children[index - 1]
            child.keys.insert(0, parent.keys[index - 1])
            parent.keys[index - 1] = left_sibling.keys.pop()
            if not left_sibling.is_leaf():
                child.children.insert(0, left_sibling.children.pop())

        # Case 2: Borrow from the right sibling
        elif index < len(parent.children) - 1 and len(parent.children[index + 1].keys) > 1:
            right_sibling = parent.children[index + 1]
            child.keys.append(parent.keys[index])
            parent.keys[index] = right_sibling.keys.pop(0)
            if not right_sibling.is_leaf():
                child.children.append(right_sibling.children.pop(0))

        # Case 3: Merge with a sibling
        elif index > 0:
            left_sibling = parent.children[index - 1]
            left_sibling.keys.append(parent.keys.pop(index - 1))
            left_sibling.keys.extend(child.keys)
            if not child.is_leaf():
                left_sibling.children.extend(child.children)
            parent.children.pop(index)
        else:
            right_sibling = parent.children[index + 1]
            child.keys.append(parent.keys.pop(index))
            child.keys.extend(right_sibling.keys)
            if not right_sibling.is_leaf():
                child.children.extend(right_sibling.children)
            parent.children.pop(index + 1)

        # If the parent is empty (root case), make the child the new root
        if parent == self.root and len(parent.keys) == 0:
            self.root = parent.children[0]


def createTreeItem(key, value):
    return key

# Test code
if __name__ == "__main__":
    # First test case
    t = TwoThreeFourTree()
    print(t.isEmpty())
    print(t.insertItem(createTreeItem(8, 8)))
    print(t.insertItem(createTreeItem(5, 5)))
    print(t.insertItem(createTreeItem(10, 10)))
    print(t.insertItem(createTreeItem(15, 15)))
    print(t.isEmpty())
    print(t.retrieveItem(5)[0])
    print(t.retrieveItem(5)[1])
    t.inorderTraverse(print)
    print(t.save())
    t.load({'root': [10], 'children': [{'root': [5]}, {'root': [11]}]})
    t.insertItem(createTreeItem(15, 15))
    print(t.deleteItem(0))
    print(t.save())
    print(t.deleteItem(10))
    print(t.save())

    # Second test case
    print("\nSecond test case:")
    t = TwoThreeFourTree()
    t.load({'root': [5], 'children': [{'root': [2], 'children': [{'root': [1]}, {'root': [3, 4]}]},
                                      {'root': [12], 'children': [{'root': [10]}, {'root': [13, 15, 16]}]}]})
    t.deleteItem(13)
    t.deleteItem(10)
    t.deleteItem(16)
    print(t.save())