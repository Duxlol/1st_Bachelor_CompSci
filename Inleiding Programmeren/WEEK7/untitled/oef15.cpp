#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n<=1) return false;
    if (n==2) return true;
    int limit = sqrt(n);
    for(int i=2;i<=limit;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout<<isPrime(1)<<endl;
    cout<<isPrime(2)<<endl;
    cout<<isPrime(18)<<endl;
    cout<<isPrime(29)<<endl;
}