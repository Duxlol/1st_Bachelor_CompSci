#include <iostream>
using namespace std;
void print(char* a) {
    while (*a != '\0') {
        cout << *a;
        a++;
    }
    cout << endl;
}