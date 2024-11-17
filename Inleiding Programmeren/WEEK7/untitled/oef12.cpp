#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double normVector(vector<int> v1) {
    double total = 0;
    for(int num : v1) {
        total += pow(num,2);
    }
    return sqrt(total);
}
int main() {
    vector<int> v1 = {1, 2, 3, 4, 5,1};
    vector<int> v2 = {6, 7, 8, 9, 10};
    vector<int> v3 = {-1, 1, 0, 2, 100};
    cout<<normVector(v1)<< endl;
    cout<<normVector(v2)<< endl;
    cout<<normVector(v3)<< endl;

}