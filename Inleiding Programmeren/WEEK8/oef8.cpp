#include <iostream>
using namespace std;

char print(char* a, int n) {
    for(int i = 0; i<n; i++) {
        cout << a[i];
    }
    cout << "\n";
}