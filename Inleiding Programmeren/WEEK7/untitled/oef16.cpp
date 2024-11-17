#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2==0 || n % 3==0) return false;
    int i = 5;

    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
        i += 6;
    return true;
    }
}
int main() {
    cout<<isPrime(1)<<endl;
    cout<<isPrime(2)<<endl;
    cout<<isPrime(18)<<endl;
    cout<<isPrime(29)<<endl;
}