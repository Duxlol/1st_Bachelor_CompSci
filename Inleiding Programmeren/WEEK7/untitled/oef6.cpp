#include <iostream>
#include <map>
using namespace std;

void removeAndPrint(map<int,string> contacts, int telToBeRemoved){
    map<int,string>::iterator it = contacts.find(telToBeRemoved);

    if (it != contacts.end()) {
        contacts.erase(it);
    }
    for(pair<int,string> names : contacts) {
        cout << names.second << ": " << names.first << endl;
    }
}

int main(){
    removeAndPrint({{123, "Toon"}, {789, "Daphne"}, {456, "Tom"} },456);
}
