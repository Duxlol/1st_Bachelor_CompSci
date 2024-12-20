#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int capacity) : ArrayList(capacity) {}
Queue::~Queue() {
  cout << "calling destructor Queue\n";
};

//functies
void Queue::enqueue(int x) {
  add(x);
}

int Queue::dequeue() {
  int item;
  get(0,item);
  del(0);

  return item;
}