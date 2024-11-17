#include <iostream>
#include <vector>
using namespace std;

string vecToString(vector<int> v1) {
    string result = "[";
    for(int i = 0; i < v1.size(); i++) {
        result += to_string(v1[i]);
        if (i != v1.size() -1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
int main() {
    vector<int> v1 = {1, 2, 3, 4, 5, 1};
    vector<int> v2 = {6, 7, 8, 9, 10, 2};
    cout<<vecToString(v1)<< endl;
    cout<<vecToString(v2)<< endl;
}