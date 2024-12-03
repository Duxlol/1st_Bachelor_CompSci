#include <float.h>
#include <iostream>
using namespace std;

struct ArrayList {
    int size;
    int capacity;
    int* items;
};

ArrayList* createList(int capacity) {
    ArrayList* data = new ArrayList;
    data->size = 0;
    data->capacity = capacity;
    data->items = new int[capacity];
    return data;
}

void clearList(ArrayList* list) {
    list->size = 0;
}

void destroyList(ArrayList* list) {
    delete[] list->items;
    delete list;
}

bool isEmpty(ArrayList* list) {
    if (list->size == 0) {
        return 1;
    }
    return 0;
}

int getSize(ArrayList* list) {
    return list->size;
}

void printList(ArrayList* list) {
    cout << "[";
    for (int i=0; i<list->size; i++) {
        cout << list->items[i];
        if (i<list->size-1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}