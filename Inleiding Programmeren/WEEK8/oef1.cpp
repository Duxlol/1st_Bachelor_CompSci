#include <iostream>
using namespace std;

bool integerDivision(int teller, int noemer, int& quotient, int& rest) {
    quotient = teller/noemer;
    rest = teller%noemer;
    return rest==0;
}

int main() {
    int teller1 = 18;
    int noemer1 = 9;
    int quotient = -1;
    int rest = -1;
    int noemer2 = 8;

    cout << integerDivision(teller1, noemer1, quotient, rest) << endl; // Verwacht: 1 (true)
    cout << quotient << endl; // Verwacht: 2
    cout << rest << endl;     // Verwacht: 0

    cout << integerDivision(teller1, noemer2, quotient, rest) << endl; // Verwacht: 0 (false)
    cout << quotient << endl; // Verwacht: 2
    cout << rest << endl;     // Verwacht: 2

    return 0;
}