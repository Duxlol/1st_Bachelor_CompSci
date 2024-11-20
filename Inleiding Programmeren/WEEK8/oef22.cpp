#include <algorithm>
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

void print(int* pointers[], int** begin, int** end) {
    while (begin <= end) {
        cout << **begin << " ";
        begin++;
    }
    cout << endl;
}

void reversecopy(int original[], int* empty[], int size) {
    int i = 0;
    for (int j = size-1 ; j >= 0 ; j--) {
        empty[i] = &original[j];
        i++;
    }
}

int findMin(int* original[], int begin, int end) {
    int min = *original[begin];
    int minIndex = begin;
    int i = begin;
    while (i <= end-1) {
        if (*original[i] < min) {
            min = *original[i];
            minIndex = i;
        }
        i++;
    }
    return minIndex;
}

int sortedcopy(int original[], int* empty[], int size) {
    shallowcopy(original, empty, size);
    for (int i = 0; i < size-1; i++) {
        int minIndex = findMin(empty, i, size-1);

        // swap pointers
        int* temp = empty[i];
        empty[i] = empty[minIndex];
        empty[minIndex] = temp;
    }

}