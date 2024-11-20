#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> readNumbers(string filename) {
    int number;
    vector<int> v;
    ifstream fin;
    fin.open(filename);

    while (fin >> number) {
        v.push_back(number);
    }
    fin.close();
    return v;
}

void writeNumbersInReverse(string filename, vector<int>& numbers) {
    ofstream f(filename);
    for (int i = numbers.size()-1; i >= 0; i--) {
        int lastnumber = numbers.back();
        f << lastnumber << endl;
        numbers.pop_back();
    }
   f.close();
}

int main() {
    vector<int> getallen = {5,6,7,8,9};
    writeNumbersInReverse("output.txt",getallen);
    vector<int> getallen2 = readNumbers("output.txt");
    for(auto i: getallen2){
        cout << i << endl;
    }

    return 0;
}