#include <iostream>
using namespace std;

void shallowcopy(int* original, int* results[], int size) {
    for (int i = 0; i < size; i++) {
        results[i] = &original[i];
    }
}

int** getPointer(int* original[], int size, int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    return &original[index];
}

