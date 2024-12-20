#include <iostream>

#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList(int capacity){
    this->size = 0;
    this->capacity = capacity;
    this->items = new int[capacity];
}

ArrayList::~ArrayList() {
    delete[] this->items;
    cout<<"calling destructor ArrayList\n";
}

// CLEARLIST
void ArrayList::clearList(){
    this->size = 0;
    for(int i=0; i<this->capacity; i++){
        this->items[0] = 0;
    }
}

// ISEMPTY
bool ArrayList::isEmpty() const {
    return this->size == 0;
}

// GETSIZE
int ArrayList::getSize() const {
    return this->size;
}

// SET
bool ArrayList::set(int index, int value){
    //extra check of index > size
    if(index >= this->size || index <0 ){
        return false;
    }
    else{
        this->items[index] = value;
        return true;
    }
}


// GET
bool ArrayList::get(int index,int& item) const{
    //extra check of index > size
    if(index >= this->size or index <0 ){
        return false;
    }
    item = this->items[index];
    return true;
    }

// DEL

bool ArrayList::del(int index){
    if (index < 0 || index >= this->size) {
        return false;
    }
    for (int i = index; i < this->size - 1; i++) {
        this->items[i] = this->items[i + 1];
    }
    this->size--;
    return true;
}


// DOUBLECAPACITY

void ArrayList::doubleCapacity(){
    //double size
    int* newItems = new int[this->capacity * 2];
    //copy content lst->items to newItems
    for(int i=0; i<this->size; i++){
        newItems[i] = this->items[i];
    }
    //delete previous list
    delete[] this->items;
    //update new lst
    this->items = newItems;
    this->capacity = this->capacity * 2;
}

// ADD

void ArrayList::add(int newItem) {
    //checks if list has reached it capacity, if so it will double the capacity such that new item will fit in the list
    if(this->size == this->capacity){
        doubleCapacity();
    }
    //add element
    this->items[this->size] = newItem;
    //increment size
    this->size++;
}

// INSERT

void ArrayList::insert(int index, int newItem){
    //checks if list has reached it capacity, if so it will double the capacity such that new item will fit in the list
    if(this->size == this->capacity){
        doubleCapacity();
    }
    //"shift" items to the right > index, start from high to low
    for(int i=this->size - 1; i>=index; i--){
        this->items[i+1] = this->items[i];
    }
    this->items[index] = newItem;
    this->size +=1;
}

// PRINT

void ArrayList::print()const{
    cout << "[";
    for(int i=0; i < this->size; i++){
        cout << this->items[i];
        if(i != this->size -1)
            cout << ",";
    }
    cout << "]" << endl;
}
