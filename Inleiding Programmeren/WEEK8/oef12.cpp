#include <iostream>
#include <cmath>
using namespace std;

int computeDiscriminant (int a, int b,int c) {
    int bsquared = pow(b,2);
    int fourac = 4*a*c;
    int discriminant = bsquared - fourac;
    return discriminant;
}