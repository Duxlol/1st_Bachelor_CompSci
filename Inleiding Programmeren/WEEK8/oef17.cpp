#include <iostream>
using namespace std;

void shallowcopy(int* original, int* results[], int size) {
    for (int i = 0; i < size; i++) {
        results[i] = &original[i];
    }
}

int main() {
    // Example array
    int a[] = {1, -3, -6, 2};
    // Create an array of pointers (not initialized yet)
    int* b[4];

    // Perform shallow copy
    shallowcopy(a, b, 4);

    // Access and print the values through the pointers in b
    cout << *b[0] << endl;  // Output: 1 (first element of the original array)
    cout << *b[1] << endl;  // Output: -3
    cout << *b[2] << endl;  // Output: -6
    cout << *b[3] << endl;  // Output: 2

    // Modify the original array
    a[0] = 5;

    // Access and print the updated value through pointers in b
    cout << *b[0] << endl;  // Output: 5 (since it's a shallow copy)

    return 0;
}