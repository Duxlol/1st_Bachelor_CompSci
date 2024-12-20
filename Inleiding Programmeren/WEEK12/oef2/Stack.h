#include "ArrayList.h"
#ifndef STACK_h
#define STACK_H



class Stack: public ArrayList {
public:
    Stack(int capacity);
    ~Stack();

    // functies
    void push(int x);
    int pop();
};




#endif //STACK_H
