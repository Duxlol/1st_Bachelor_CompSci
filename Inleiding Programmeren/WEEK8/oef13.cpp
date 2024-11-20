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

int solveQuadraticEquation (vector<int>& v, double& x1, double& x2) {
    int a = v[0];
    int b = v[1];
    int c = v[2];
    int discriminant = computeDiscriminant(a,b,c);
    if (discriminant < 0) {
        return 0;
    } else if (discriminant == 0) {
        x1 = x2 = -b/(2.0*a);
        return 1;
    } else {
        x1 = (-b + sqrt(discriminant))/(2.0*a);
        x2 = (-b - sqrt(discriminant))/(2.0*a);
        return 2;
    }
}

int main() {
    vector<int> abc1 = {1, -2, 1};
    vector<int> abc2 = {1, -2, -3};
    vector<int> abc3 = {10, 5, 2};
    double x1;
    double x2;
    cout<<solveQuadraticEquation(abc1, x1, x2)<<endl;
    cout<<x1<<endl;
    cout<<solveQuadraticEquation(abc2, x1, x2)<<endl;
    cout<<x1<<endl;
    cout<<x2<<endl;
    cout<<solveQuadraticEquation(abc3, x1, x2)<<endl;


}