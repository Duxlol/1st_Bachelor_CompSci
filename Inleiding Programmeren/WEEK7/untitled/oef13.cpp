#include <iostream>
using namespace std;

void printTextRectangleFilled(int width, int height) {
    for(int i = 0; i < height;i++) {    /* hoogte aan asteriksen */
        for(int j=0; j < width;j++) {    /* width keer asteriksen, want er is geen * string operator zoals in python*/
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    printTextRectangleFilled(5, 6);
}