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

int main() {
    int* array = nullptr;
    int length = 0;
    leesMetLengte(array,length);

    int total = 0;
    for (int i = 0; i < length ; ++i) {
        total += array[i];
    }
    double average = total/(length*1.0);

    double median;
    if (length % 2 == 0) {
        median = (array[length/2-1] + array[length/2])/2.0;
    } else {
        median = array[length/2];
    }

    cout << "Gemiddelde: " << average << endl;
    cout << "Mediaan: " << median << endl;

    delete[] array;

    return 0;
}