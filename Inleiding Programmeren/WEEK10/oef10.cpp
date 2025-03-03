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

bool set(LinkedList* list, int index, string newItem) {
    if (index < 0 || index >= list->size) {
        return false;
    }
    
    Node* newNode = new Node;
    newNode->item = newItem;

    // insert at beginning
    if (index == 0) {
        newNode->next = list->head;
        newNode->prev = nullptr;
        if (list->head) {
            list->head->prev = newNode;
        }
        list->head = newNode;
    }

    else {
        Node* tmp = list->head;
        for (int i = 0; i<index-1;i++) {
            tmp = tmp->next;
        }

        newNode->next = tmp->next;
        newNode->prev = tmp;
        if (tmp->next) {
            tmp->next->prev = newNode;
        }
        tmp->next = newNode;
    }
    list->size++;
    return true;
}

bool remove(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        return false;
    }

    Node* tmp = list->head;
    for (int i = 0; i<index; i++) {
        tmp = tmp->next;
    }

    // remove head node
    if (tmp == list->head) {
        list->head = tmp->next;
        if (list->head != nullptr) {
            list->head->prev = nullptr;
        }
    }

    // remove node anywhere else
    else {
        tmp->prev->next = tmp->next;
        if (tmp->next != nullptr) {
            tmp->next->prev = tmp->prev;
        }
    }
    delete tmp;
    list->size--;
    return true;
}

void destroyList(LinkedList* list) {
    Node* CurrentNode = list->head;
    while (CurrentNode != nullptr) {
        Node* NextNode =  CurrentNode->next;
        delete CurrentNode;
        CurrentNode = NextNode;
    }
    delete list;
}

int main() {
    LinkedList* list = createList();
    add(list, "Hello");
    add(list, "World");
    add(list, "!!");
    print(list);
    set(list, 1, "dear");
    print(list);
    remove(list,3);
    print(list);
    destroyList(list);
}