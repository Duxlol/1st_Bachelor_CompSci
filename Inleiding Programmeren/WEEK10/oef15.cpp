#include <iostream>
using namespace std;

struct User {
    string firstname;
    string lastname;
};

struct BST {
    User* value;
    int key;
    BST* leftTree;
    BST* rightTree;
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