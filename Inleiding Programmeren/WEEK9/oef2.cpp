#include <iostream>
#include <vector>
using namespace std;
vector<int*> memory;

int* allocate(int n) {
    if (n <= 0) {
        return nullptr;
    }
    int* arr = new int[n];
    memory.push_back(arr);

    return arr;
}