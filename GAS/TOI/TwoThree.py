def createTreeItem(key, val):
    return {"key": key, "value": val}

class TreeNode:
    def __init__(self, items=None, children=None):
        self.items = items if items else []
        self.children = children if children else []

    def is_leaf(self):
        return len(self.children) == 0
    def to_dict(self):
        result = {
            "root": [item["key"] for item in self.items]
        }
        if self.children:
            result["children"] = [child.to_dict() for child in self.children]
        return result

    @staticmethod
    def from_dict(data):
        items = [{"key": key, "value": key} for key in data["root"]]
        children = [TreeNode.from_dict(child) for child in data.get("children", [])]
        return TreeNode(items, children)


class TwoThreeTree:
    def __init__(self):
        self.root = None

    def isEmpty(self):
        return self.root is None

    def insertItem(self, item):
        if not self.root:
            self.root = TreeNode([item])
            return True
        result = self._insert_recursive(self.root, item)
        if isinstance(result, dict):
            self.root = TreeNode([result["middle"]], [result["left"], result["right"]])
        return True
    def _insert_recursive(self, node, item):
        if node.is_leaf():
            node.items.append(item)
            node.items.sort(key=lambda x: x["key"])
            if len(node.items) == 3:
                return self._split_node(node)
            return node
        pos = 0
        while pos < len(node.items) and item["key"] > node.items[pos]["key"]:
            pos += 1
        child_result = self._insert_recursive(node.children[pos], item)
        if isinstance(child_result, dict):
            node.items.insert(pos, child_result["middle"])
            node.children[pos] = child_result["left"]
            node.children.insert(pos + 1, child_result["right"])

            if len(node.items) == 3:
                return self._split_node(node)
        return node

    def inorderTraverse(self, visit):
        if self.root:
            self._inorder_recursive(self.root, visit)
    def _inorder_recursive(self, node, visit):
        if node.is_leaf():
            for item in node.items:
                visit(item["key"])
        else:
            for i in range(len(node.items)):
                self._inorder_recursive(node.children[i], visit)
                visit(node.items[i]["key"])
            self._inorder_recursive(node.children[-1], visit)
    def _split_node(self, node):
        middle_idx = len(node.items) // 2
        middle = node.items[middle_idx]
        left = TreeNode(items=node.items[:middle_idx])
        right = TreeNode(items=node.items[middle_idx + 1:])
        if node.children:
            left.children = node.children[:middle_idx + 1]
            right.children = node.children[middle_idx + 1:]
        return {"middle": middle, "left": left, "right": right}
    def deleteItem(self, key):
        if not self.root:
            return False
        result = self._delete_recursive(self.root, None, -1, key)
        if not self.root.items and self.root.children:
            self.root = self.root.children[0]
        return result

    def _delete_recursive(self, node, parent, parent_idx, key):
        pos = 0
        while pos < len(node.items) and key > node.items[pos]["key"]:
            pos += 1
        if pos < len(node.items) and node.items[pos]["key"] == key:
            if node.is_leaf():
                node.items.pop(pos)
            else:
                successor = self._get_min(node.children[pos + 1])
                node.items[pos] = successor
                self._delete_recursive(node.children[pos + 1], node, pos + 1, successor["key"])
                if not node.children[pos + 1].items:
                    self._rebalance(node, pos + 1)
            return True
        if node.is_leaf():
            return False
        result = self._delete_recursive(node.children[pos], node, pos, key)

        if node.children[pos] and not node.children[pos].items:
            self._rebalance(node, pos)

        return result

    def retrieveItem(self, key):
        if not self.root:
            return None, False

        return self._retrieve_recursive(self.root, key)

    def _retrieve_recursive(self, node, key):
        for item in node.items:
            if item["key"] == key:
                return item["value"], True
        if node.is_leaf():
            return None, False
        pos = 0
        while pos < len(node.items) and key > node.items[pos]["key"]:
            pos += 1
        return self._retrieve_recursive(node.children[pos], key)

    def _get_min(self, node):
        current = node
        while not current.is_leaf():
            current = current.children[0]
        return current.items[0]

    def _rebalance(self, parent, child_idx):
        child = parent.children[child_idx]
        if child_idx > 0:
            left_sibling = parent.children[child_idx - 1]
            if len(left_sibling.items) > 1:
                child.items.insert(0, parent.items[child_idx - 1])
                parent.items[child_idx - 1] = left_sibling.items.pop()
                if left_sibling.children:
                    child.children.insert(0, left_sibling.children.pop())
                return
        if child_idx < len(parent.children) - 1:
            right_sibling = parent.children[child_idx + 1]
            if len(right_sibling.items) > 1:
                child.items.append(parent.items[child_idx])
                parent.items[child_idx] = right_sibling.items.pop(0)
                if right_sibling.children:
                    child.children.append(right_sibling.children.pop(0))
                return
        if child_idx > 0:
            left_sibling = parent.children[child_idx - 1]
            left_sibling.items.append(parent.items.pop(child_idx - 1))
            left_sibling.items.extend(child.items)
            if child.children:
                left_sibling.children.extend(child.children)
            parent.children.pop(child_idx)
        else:
            right_sibling = parent.children[child_idx + 1]
            child.items.append(parent.items.pop(child_idx))
            child.items.extend(right_sibling.items)
            if right_sibling.children:
                child.children.extend(right_sibling.children)
            parent.children.pop(child_idx + 1)

    def save(self):
        return self.root.to_dict() if self.root else {}

    def load(self, data):
        self.root = TreeNode.from_dict(data)

if __name__ == "__main__":
    t = TwoThreeTree()
    print(t.isEmpty())
    print(t.insertItem(createTreeItem(8,8)))
    print(t.insertItem(createTreeItem(5,5)))
    print(t.isEmpty())
    print(t.retrieveItem(5)[0])
    print(t.retrieveItem(5)[1])
    t.inorderTraverse(print)
    print(t.save())
    t.load({'root': [10],'children':[{'root':[5]},{'root':[11]}]})
    t.insertItem(createTreeItem(15,15))
    print(t.deleteItem(0))
    print(t.save())
    print(t.deleteItem(10))
    print(t.save())

    print("\nSecond test case:")
    t = TwoThreeTree()
    t.load({'root': [5], 'children': [{'root': [2], 'children': [{'root': [1]}, {'root': [3, 4]}]},
                                      {'root': [12], 'children': [{'root': [10]}, {'root': [13, 15, 16]}]}]})
    t.deleteItem(13)
    t.deleteItem(10)
    t.deleteItem(16)
    print(t.save())