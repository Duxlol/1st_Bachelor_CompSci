#include <iostream>
using namespace std;

void shiftLeft(int* a,int* b, int* c) {
    int tempa =  *a;
    *a = *b;
    *b = *c;
    *c = tempa;
}
