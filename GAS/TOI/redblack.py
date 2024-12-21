class TreeNode:
    def __init__(self, key, value, color="red"):
        self.key = key
        self.value = value
        self.color = color  # "red" or "black"
        self.left = None
        self.right = None
        self.parent = None

class RedBlackTree:
    def __init__(self):
        self.nil = TreeNode(None, None, color="black")  # Sentinel node for NIL
        self.root = self.nil

    def createTreeItem(self, key, value):
        return TreeNode(key, value)

    def isEmpty(self):
        return self.root == self.nil

    def insertItem(self, item):
        if not isinstance(item, TreeNode):
            return False

        self.insert(item.key, item.value)
        return True

    def insert(self, key, value):
        new_node = self.createTreeItem(key, value)
        new_node.left = self.nil
        new_node.right = self.nil

        parent = None
        current = self.root

        while current != self.nil:
            parent = current
            if new_node.key < current.key:
                current = current.left
            else:
                current = current.right

        new_node.parent = parent

        if parent is None:
            self.root = new_node  # Tree was empty
        elif new_node.key < parent.key:
            parent.left = new_node
        else:
            parent.right = new_node

        new_node.color = "red"
        self.fix_insert(new_node)

    def fix_insert(self, node):
        while node != self.root and node.parent.color == "red":
            if node.parent == node.parent.parent.left:
                uncle = node.parent.parent.right
                if uncle.color == "red":
                    node.parent.color = "black"
                    uncle.color = "black"
                    node.parent.parent.color = "red"
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    node.parent.color = "black"
                    node.parent.parent.color = "red"
                    self.right_rotate(node.parent.parent)
            else:
                uncle = node.parent.parent.left
                if uncle.color == "red":
                    node.parent.color = "black"
                    uncle.color = "black"
                    node.parent.parent.color = "red"
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    node.parent.color = "black"
                    node.parent.parent.color = "red"
                    self.left_rotate(node.parent.parent)
        self.root.color = "black"

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.nil:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.nil:
            y.right.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def retrieveItem(self, key):
        node = self.findNode(self.root, key)
        if node != self.nil:
            return (node.key, True)
        return (None, False)

    def findNode(self, node, key):
        if node == self.nil or key == node.key:
            return node
        if key < node.key:
            return self.findNode(node.left, key)
        else:
            return self.findNode(node.right, key)

    def inorderTraverse(self, visit):
        def traverse(node):
            if node != self.nil:
                traverse(node.left)
                visit(node.key)
                traverse(node.right)

        traverse(self.root)

    def save(self):
        def serialize(node):
            if node == self.nil:
                return None
            return {
                'root': node.key,
                'color': node.color,
                'children': [serialize(node.left), serialize(node.right)]
            }

        return serialize(self.root)

    def load(self, data):
        def deserialize(data):
            if data is None:
                return self.nil

            if 'children' not in data:
                data['children'] = [None, None]

            left_child = data['children'][0] if data['children'][0] is not None else None
            right_child = data['children'][1] if data['children'][1] is not None else None

            node = TreeNode(data['root'], data['root'], color=data['color'])
            node.left = deserialize(left_child)
            node.right = deserialize(right_child)

            if node.left != self.nil:
                node.left.parent = node
            if node.right != self.nil:
                node.right.parent = node

            return node

        self.root = deserialize(data)
        self.root.color = "black"
        self.root.parent = None

    def deleteItem(self, key):
        # This is a stub. Full deletion implementation needed.
        return False

def createTreeItem(key, value):
    return TreeNode(key, value)


if __name__ == "__main__":
    t = RedBlackTree()
    print(t.isEmpty())
    print(t.insertItem(createTreeItem(8,8)))
    print(t.insertItem(createTreeItem(5,5)))
    print(t.insertItem(createTreeItem(10,10)))
    print(t.insertItem(createTreeItem(15,15)))
    print(t.isEmpty())
    print(t.retrieveItem(5)[0])
    print(t.retrieveItem(5)[1])
    t.inorderTraverse(print)
    print(t.save())
    t.load({'root': 8,'color': 'black','children':[{'root':5,'color': 'black'},{'root':10,'color': 'black'}]})
    t.insertItem(createTreeItem(15,15))
    print(t.deleteItem(0))
    print(t.save())
    print(t.deleteItem(10))
    print(t.save())