#include <iostream>
using namespace std;

void shiftLeft(int& a,int& b, int& c) {
int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 111;
    int b = 32;
    int c = 89;
    for(int i = 0; i < 10; i++){
        shiftLeft(a,b,c);
        cout << "(a,b,c) == (" << a << "," << b << "," << c << ")" << endl;
    }

    return 0;
}