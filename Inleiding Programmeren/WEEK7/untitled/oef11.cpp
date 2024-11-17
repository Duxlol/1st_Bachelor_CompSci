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
vector<int> addVectors(vector<int> v1, vector<int> v2) {
    vector<int> v3;
    int i = 0;
    for(int num : v1) {
        v3.push_back(v1[i] + v2[i]);
        i++;
    }
    return v3;
}
int main() {
    vector<int> v1 = {1, 2, 3, 4, 5, 1};
    vector<int> v2 = {6, 7, 8, 9, 10, 2};
    vector<int> v3 = {-1, 1, 0, 2, 100, 3};
    vector<int> v4 = addVectors(v1, v2);
    vector<int> v5 = addVectors(v2, v1);
    vector<int> v6 = addVectors(v1, v3);
    cout<<vecToString(v4)<< endl;
    cout<<vecToString(v5)<< endl;
    cout<<vecToString(v6)<< endl;
}