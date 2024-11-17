#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<string,int> createFreqTab(vector<string> woorden){
    map<string,int> freqMap;
    for(string woord : woorden) {
        freqMap[woord]++;
    }
    return freqMap;
}

void printFreqTab(map<string,int> freqtab){
    for(map<string,int>::iterator it=freqtab.begin();it!=freqtab.end();it++) {
        cout << it->first << " " << it->second << endl;
    }
}


int main(){
    map<string,int> freqtab = createFreqTab({"dit","is","een","dit","een","dit","hallo","dit"});
    printFreqTab(freqtab);
}