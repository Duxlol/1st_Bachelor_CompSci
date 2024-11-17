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
vector<int> addVector(vector<int> v1, int x) {
    int i = 0;
    for(int num : v1) {
        v1[i] = num + x;
        i++;
    }
    return v1;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5, 1};
    vector<int> v2 = {6, 7, 8, 9, 10, 2};
    vector<int> v3 = addVector(v1, 4);
    vector<int> v4 = addVector(v2, -2);
    cout<<vecToString(v3)<< endl;
    cout<<vecToString(v4)<< endl;
}