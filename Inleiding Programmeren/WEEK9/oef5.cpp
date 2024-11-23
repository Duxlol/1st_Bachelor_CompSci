#include <iostream>
using namespace std;

double mediaan(int* a, int n) {
    if (n % 2 == 0) {
        int midden1 = (n/2)-1;
        int midden2 = (n/2);
        double mediaan = (double)(a[midden1]+a[midden2])/2;
        return mediaan;
    }
    int midden = ((n+1)/2)-1;
    return a[midden];
}