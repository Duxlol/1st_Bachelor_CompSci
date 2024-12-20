#include <iostream>
using namespace std;

#include "DenTweede.h"
#include "DenDerde.h"
#include "EnDeVierde.h"

class DenEerste : public DenTweede {
public:
    DenEerste() : v() { // Initialiseer `EnDeVierde` expliciet
        DenDerde d;
        cout << "4, ";
    }

    virtual ~DenEerste() {
        cout << "6, ";
    }

private:
    EnDeVierde v; // Member van klasse `DenEerste`
};

int main() {
    DenEerste d;
    return 0;
}
