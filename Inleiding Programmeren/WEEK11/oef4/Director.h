using namespace std;
#include <string>
#ifndef DIRECTOR_H
#define DIRECTOR_H

class Director {
public:
    Director(const string &firstname, const string &lastname);

private:
    string firstname;
    string lastname;
};

#endif //DIRECTOR_H
