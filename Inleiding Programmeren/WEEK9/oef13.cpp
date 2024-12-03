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