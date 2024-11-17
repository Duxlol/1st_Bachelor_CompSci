#include <iostream>
#include <map>
using namespace std;

void printContacts(map<int,string> contacts){
    for(map<int,string>::iterator it=contacts.begin();it!=contacts.end();it++) {
        cout << it->second << ": " << it->first << endl;
    }
}

int main(){
    printContacts({{123, "Toon"}, {789, "Daphne"}, {456, "Tom"} , {159, "Stephen"} });
}
