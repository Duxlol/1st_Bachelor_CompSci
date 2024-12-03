#include <iostream>
using namespace std;

int leesGetal() {
    static int values[] = {3, 10, 20, 30};
    static int index = 0;
    return values[index++];
}


void leesMetLengte(int*& array, int& length) {
    length = leesGetal();
    array = new int[length];

    /* filling of the array */
    for (int i=0 ; i < length ; i++) {
     array[i] = leesGetal();
    }
}

int main(){
    int aantal = leesGetal(); //geeft bv 3
    cout << "We lezen " << aantal << " getallen in die reeds gesorteerd zijn: " << leesGetal() << leesGetal() << leesGetal() << endl;
}