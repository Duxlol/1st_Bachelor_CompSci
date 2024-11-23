#include <iostream>
using namespace std;

double gemiddelde(int* a,int n) {
    int total = 0;
    for (int i = 0 ; i < n ; i++) {
        total += a[i];
    }
    double gemiddelde = double(total)/n;
    return gemiddelde;
}