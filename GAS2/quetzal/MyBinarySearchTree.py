# zelf gemaakte BST van GAS Sem 1 | Thijs Van Schel

class TreeNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None


def createTreeItem(key, val):
    return TreeNode(key, val)


class BST:
    def __init__(self):
        self.root = None

    def isEmpty(self):
        return self.root is None

    def searchTreeInsert(self, item):
        def insert(node, item):
            if item.key < node.key:
                if node.left is None:
                    node.left = item
                    return True
                return insert(node.left, item)
            elif item.key > node.key:
                if node.right is None:
                    node.right = item
                    return True
                return insert(node.right, item)
            return False

        if self.isEmpty():
            self.root = item
            return True
        return insert(self.root, item)

    def searchTreeRetrieve(self, key):
        def retrieve(node, key):
            if node is None:
                return None, False
            if key == node.key:
                return node.value, True
            elif key < node.key:
                return retrieve(node.left, key)
            else:
                return retrieve(node.right, key)

        return retrieve(self.root, key)

    def searchTreeDelete(self, key):
        def delete(node, key):
            if node is None:
                return node, False
            if key < node.key:
                node.left, deleted = delete(node.left, key)
            elif key > node.key:
                node.right, deleted = delete(node.right, key)
            else:
                if node.left is None:
                    return node.right, True
                elif node.right is None:
                    return node.left, True
                min_larger_node = getMin(node.right)
                node.key, node.value = min_larger_node.key, min_larger_node.value
                node.right, deleted = delete(node.right, node.key)
            return node, deleted

        def getMin(node):
            while node.left is not None:
                node = node.left
            return node

        self.root, deleted = delete(self.root, key)
        return deleted

    def inorderTraverse(self, visit):
        def inorder(node):
            if node:
                inorder(node.left)
                visit(node.value)
                inorder(node.right)

        inorder(self.root)

    def save(self):
        def save_node(node):
            if node is None:
                return None
            node_representation = {'root': node.key}
            children = [save_node(node.left), save_node(node.right)]
            if any(children):
                node_representation['children'] = children
            return node_representation

        return save_node(self.root)

    def load(self, tree_dict):
        def load_node(tree_dict):
            if tree_dict is None:
                return None
            node = TreeNode(tree_dict['root'], tree_dict['root'])
            if 'children' in tree_dict:
                node.left = load_node(tree_dict['children'][0])
                node.right = load_node(tree_dict['children'][1])
            return node

        self.root = load_node(tree_dict)