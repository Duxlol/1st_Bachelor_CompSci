#include <iostream>
using namespace std;

void throwDice(int &d1, int &d2) {
    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;
}

int main() {
    int d1,d2;
    throwDice(d1,d2);
    return 0;
}
