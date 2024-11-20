#include <iostream>
using namespace std;

int telKlinkers(char* karakters) {
    int total = 0;
    while (*karakters != '\0') {
        if(*karakters == 'a' || *karakters == 'e' || *karakters == 'i' || *karakters == 'o' || *karakters == 'u') {
            total += 1;
            karakters++;
        }
        else karakters++;
    }
    return total;
}

int main()
{
    char zin[] = "Dit is geen zin. Het heeft immers geen zin, zo'n zinnetje.";
    cout << telKlinkers(zin) << endl;
    return 0;
}