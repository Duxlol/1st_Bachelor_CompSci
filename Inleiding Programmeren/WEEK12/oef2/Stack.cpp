#include <iostream>
#include "Stack.h"
using namespace std;


Stack::Stack(int capacity) : ArrayList(capacity) {}
Stack::~Stack() {
    cout << "calling destructor Stack\n";
}

void Stack::push(int x) {
    // add from arraylist
    add(x);
}

int Stack::pop() {
    // del from arraylist
    if (!isEmpty()){
        int item;
        int lastElement = getSize()-1;
        get(lastElement, item);
        del(lastElement);
        return item;
    }
}

