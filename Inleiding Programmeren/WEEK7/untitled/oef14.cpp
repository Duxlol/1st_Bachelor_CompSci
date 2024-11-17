#include <iostream>
using namespace std;

void printTextRectangleOutline(int width, int height) {     /* bovenste lijn */
    for(int i=0; i < width;i++) {
            cout << "*";
    }

    cout << endl;   /* nieuwe lijn */

    for(int j=0; j < height-2;j++) {    /* lijnen met lege plaatsen */
        cout << "*";
        for(int l=0;l<width-2;l++) {
            cout << " ";
        }
        cout << "*" << endl;
    }
    for(int i=0; i < width;i++) {
        cout << "*";
    }
}

int main() {
    printTextRectangleOutline(4, 3);
}