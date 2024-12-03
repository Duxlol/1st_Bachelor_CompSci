#include <iostream>
using namespace std;



struct MyArray {
    int* array;
    int length;

};

int leesGetal() {
    static int values[] = {3, 10, 20, 30};
    static int index = 0;
    return values[index++];
}


MyArray leesMetLengte() {
    MyArray result;
    result.length = leesGetal();
    result.array = new int[result.length];

    /* filling of the array */
    for (int i=0 ; i < result.length ; i++) {
        result.array[i] = leesGetal();
    }
    return result;
}

double average(const MyArray& arr) {
    int total = 0;
    for (int i = 0; i < arr.length ; ++i) {
        total += arr.array[i];
    }
    return total/(arr.length*1.0);
}

double median(const MyArray& arr) {
    if (arr.length % 2 == 0) {
        return (arr.array[arr.length/2-1] + arr.array[arr.length/2])/2.0;
    } else {
        return arr.array[arr.length/2];
    }
}

int main() {
    MyArray arr = leesMetLengte();
    double ave = average(arr);
    cout << "Gemiddelde: " << ave << endl;
    double med = median(arr);
    cout << "Mediaan: " << med << endl;

    delete[] arr.array;
    return 0;
}