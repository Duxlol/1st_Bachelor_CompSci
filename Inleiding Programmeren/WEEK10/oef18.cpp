#include <iostream>
using namespace std;

struct User {
    string firstname;
    string lastname;
};

struct BST {
    User* value = nullptr;
    int key = 0;
    BST* leftTree = nullptr;
    BST* rightTree = nullptr;
};

BST* createBST() {
    return nullptr;
}

bool isEmpty(BST* bst) {
    if (bst == nullptr) {
        return 1;
    } return 0;
}

void destroy(BST* bst) {
    if (bst != nullptr) {
        destroy(bst->leftTree);
        destroy(bst->rightTree);
        delete bst->value;
        delete bst;
    }
}

string save(BST* bst) {

    if (bst == nullptr) {
        return "{}";
    }

    string total = "{'root': " + to_string(bst->key);

    // left tree
    if (bst->leftTree != nullptr) {
        total += ", 'left': " + save(bst->leftTree);
    }

    // right tree
    if (bst->rightTree != nullptr) {
        total += ", 'right': " + save(bst->rightTree);
    }
    total += "}";
    return total;
}

void insert(BST*& bst, int key, User* value) {
    if (bst == nullptr) {
        bst = new BST();
        bst->key = key;
        bst->value = value;
        return;
    }

    if (key < bst->key) {
        // left tree
        insert(bst->leftTree, key, value);
    } else if (key > bst->key) {
        // right tree
        insert(bst->rightTree, key, value);
    } else if (key == bst->key) {
        // key alr exists
        delete bst->value;
        bst->value = value;
    }
}

void visit(User* user, int key) {
    cout << key << user->firstname << " " << user->lastname << endl;
}

User* find(BST* bst, int key) {
    if (bst == nullptr) {
        return nullptr;
    }

    if (bst->key == key) {
        return bst->value;
    }
    if (bst->key < key) {
        // zoek verder in left tree
        return find(bst->rightTree, key);
    }   else {
        // zoek verder in right tree
        return find(bst->leftTree, key);
    }
}