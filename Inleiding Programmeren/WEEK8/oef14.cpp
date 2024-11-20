#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int computeDiscriminant (int a, int b,int c) {
    int bsquared = pow(b,2);
    int fourac = 4*a*c;
    int discriminant = bsquared - fourac;
    return discriminant;
}

int solveQuadraticEquation (int* a, double* x1, double* x2) {
    /* a[0] = a;  */
    /* a[1] = b;  */
    /* a[2] = c   */
    int discriminant = computeDiscriminant(a[0],a[1],a[2]);
    if (discriminant < 0) {
        return 0;
    } else if (discriminant == 0) {
        *x1 = *x2 = -a[1]/(2.0*a[0]);
        return 1;
    } else {
        *x1 = (-a[1] + sqrt(discriminant))/(2.0*a[0]);
        *x2 = (-a[1] - sqrt(discriminant))/(2.0*a[0]);
        return 2;
    }
}

int main() {
    int abc1[] = {1, -2, 1};
    int *p_abc1 = abc1;
    int abc2[] = {1, -2, -3};
    int *p_abc2 = &abc2[0];
    int abc3[] = {10, 5, 2};
    int *p_abc3 = abc3;
    double x1;
    double x2;

    double *p_x1 = &x1;
    double *p_x2 = &x2;

    cout<<solveQuadraticEquation(p_abc1, p_x1, p_x2)<<endl;
    cout<<x1<<endl;
    cout<<solveQuadraticEquation(p_abc2, p_x1, p_x2)<<endl;
    cout<<x1<<endl;
    cout<<x2<<endl;
    cout<<solveQuadraticEquation(p_abc3, p_x1, p_x2)<<endl;


}