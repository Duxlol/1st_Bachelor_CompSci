#include <iostream>
using namespace std;

struct Node {
    string item;
    Node* next;
    Node* prev;
};

struct LinkedList {
    int size;
    Node* head;
};

LinkedList* createList() {
    LinkedList* list = new LinkedList;
    list->size = 0;
    list->head = nullptr;
    return list;
}