#include <iostream>
using namespace std;

bool compareByAddress(int* p, int i) {
    return p == &i;
}

int main(){
    int a = 5;
    int* b = &a;
    int c = 5;
    int d = 3;
    // boolalpha zal de waarde van de boolean afdrukken als true of false ipv 1 of 0
    cout << boolalpha << compareByValue(b,a) << endl; // geeft true
    cout << boolalpha << compareByValue(b,c) << endl; // geeft true
    cout << boolalpha << compareByValue(b,d) << endl; // geeft false

    return 0;
}