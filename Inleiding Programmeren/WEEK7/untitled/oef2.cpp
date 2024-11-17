#include <iostream>
#include <vector>
using namespace std;

void printNames(vector<string> names){
    for(int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }
}