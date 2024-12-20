#include <iostream>
using namespace std;
#include "Student.h"
#ifndef CURSUS_H
#define CURSUS_H


class Cursus : public Student {
    public:
      Cursus();
    private:
        string naam;
        string afkorting;
        int studiepunten;
};



#endif //CURSUS_H
