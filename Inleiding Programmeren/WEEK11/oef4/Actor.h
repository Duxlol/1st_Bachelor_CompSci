using namespace std;
#include <string>
#ifndef ACTOR_H
#define ACTOR_H

class Actor {
public:
    Actor(const string &firstname, const string &lastname);

private:
    string firstname;
    string lastname;
};

#endif //ACTOR_H
