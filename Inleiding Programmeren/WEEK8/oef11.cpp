#include <iostream>
using namespace std;

// bereken de absolute waarde van a
void absvalue(int &a){
    if(a < 0){
        a = -a;
    }
}

void abs(int a[],int n){
    for(int i = 0; i < n; i++){
        absvalue(a[i]);
    }
}

void print(int a[],int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}

int main(){
    int a[]  = {1,-3,-6,2};
    abs(a,4);
    print(a,4);
    return 0;
}

