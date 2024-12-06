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