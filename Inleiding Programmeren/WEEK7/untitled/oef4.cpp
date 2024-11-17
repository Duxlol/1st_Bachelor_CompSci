#include <iostream>
#include <vector>
using namespace std;

void removeFirstAndPrint(vector<string> names){
    names.erase(names.begin());
    for(vector<string>::iterator it=names.begin();it!=names.end();it++) {
        cout << *it << endl;
    }

}

int main(){
    removeFirstAndPrint({"Stephen","Toon", "Tom", "Daphne", "Wannes"});
}