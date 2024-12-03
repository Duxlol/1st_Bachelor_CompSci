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

void print(ArrayList* list) {
    cout << "[";
    for (int i=0; i<list->size; i++) {
        cout << list->items[i];
        if (i<list->size-1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

bool set(ArrayList* list, int index, int newItem) {
    if (index < 0 || index > list->size) {
        return 0;
    }
    list->items[index] = newItem;
    return 1;
}

bool get(ArrayList* list, int index, int& item) {
    if (index < 0 || index > list->size) {
        return 0;
    }
    item = list->items[index];
    return 1;
}

bool del(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        return 0;
    }
    for (int i=index; i<list->size-1;i++) {
        list->items[i] = list->items[i+1];
    }
    list->size--;
    return 1;
}

void doubleCapacity(ArrayList* list) {
    int newCapacity = list->capacity * 2;

    int* newArray = new int[newCapacity];

    for (int i=0; i<list->size;i++) {
        newArray[i] = list->items[i];
    }

    delete[] list->items;
    list->items = newArray;
    list->capacity = newCapacity;
}

void add(ArrayList* list, int newItem) {
    if (list->size == list->capacity) {
        doubleCapacity(list);
    }
    list->items[list->size] = newItem;
    list->size++;
}