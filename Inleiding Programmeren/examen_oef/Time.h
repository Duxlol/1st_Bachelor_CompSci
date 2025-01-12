#ifndef WEEK12_1_TIME_H
#define WEEK12_1_TIME_H

#include <string>

using namespace std;

class Time {
    int* hms;
    long seconden;
    void berekenHMS();
public:
    Time(long s);
    ~Time();
    string toString() const;
    void add(long s);
};



#endif //WEEK12_1_TIME_H
