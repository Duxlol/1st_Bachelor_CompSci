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

bool isEmpty(LinkedList* list) {
    return list->size == 0;
}

int getLength(LinkedList* list) {
    return list->size;
}

void add(LinkedList* list, const string& newItem) {
    Node* newNode = new Node;
    newNode->item = newItem;
    newNode-> next = nullptr;
    newNode->prev = nullptr;

    if (list->size == 0) {
        list->head = newNode;
    } else {
        Node* tmp = list->head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;

        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }
    list->size++;
}

string get(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        return "ERROR";
    }

    Node* tmp = list->head;

    for (int i = 0; i<index; i++) {
        tmp = tmp->next;
    }
    return tmp->item;
}

void print(LinkedList* list) {
    Node* tmp = list->head;
    for (int i = 0; i<list->size;i++) {
        cout << tmp->item << endl;
        tmp = tmp->next;
    }
}