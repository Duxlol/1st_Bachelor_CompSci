#include <iostream>

using namespace std;

int* verwijderMax(int* array, int length) {
    int max = array[0];
    for (int i=0; i<length; i++) {
        if ( array[i] > array[max] ) {
            max = i;
        }
    }
    int newIndex = 0;
    int* newArray = new int[length-1];
    for (int i=0; i<length;i++) {
        if (i != max) {
            newArray[newIndex] = array[i];
            newIndex++;
        }
    } return newArray;
}

// vertrek van deze main
int main(){
    int a[] = {1,5,8,2};
    int* b = verwijderMax(a,4);
    for(int i = 0; i < 3; i++){
        cout << b[i] << endl;
    }
    delete[] b;
    return 0;
}