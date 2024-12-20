#include "ArrayList.h"
#ifndef QUEUE_H
#define QUEUE_H



class Queue : public ArrayList {
  public:
    Queue(int capacity);
    ~Queue();

    // functies
    void enqueue(int x);
    int dequeue();
};



#endif //QUEUE_H
