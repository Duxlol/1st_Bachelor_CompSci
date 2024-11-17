#include <iostream>
#include <vector>
using namespace std;

int computeSom(vector<int> values){
    int a = 0;
    for(int value : values) {
        a += value;
    }
    return a;
}
int main() {
    vector<int> v={1,2,3,4,5};
    cout << "The sum is: " << computeSom(v);
}