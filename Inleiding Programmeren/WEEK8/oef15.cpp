#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> readNumbers(string filename) {
    int number;
    vector<int> v;
    ifstream fin;
    fin.open(filename);

    do {
        fin >> number;
        v.push_back(number);
    } while (!fin.eof());
    fin.close();
    return v;
}