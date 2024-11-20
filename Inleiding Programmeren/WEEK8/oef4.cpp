#include <iostream>
using namespace std;

bool compareByAddress(int* p, int& i) {
    return p == &i;
}

int main() {
    int a = 5;
    int* b = &a;
    int c = 5;
    int d = 3;

    cout << boolalpha << compareByAddress(b, a) << endl; // geeft true
    cout << boolalpha << compareByAddress(b, c) << endl; // geeft false
    cout << boolalpha << compareByAddress(b, d) << endl; // geeft false

    return 0;
}