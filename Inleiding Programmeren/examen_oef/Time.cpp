#include "Time.h"
#include <iostream>
Time::~Time() {
    delete[] hms;
};
Time :: Time (long s): seconden(s) {
    hms = new int[3];
    berekenHMS();
}

string Time::toString() const {
    return to_string(hms[0]) + ": " + to_string(hms[1]) + ": " + to_string(hms[2]);
}

void Time::berekenHMS() {
    long temp = seconden;
    int uren = temp/3600;
    temp %= 3600;
    int minuten = temp/60;
    int sec = temp%60;

    hms[0] = uren;
    hms[1] = minuten;
    hms[2] = sec;
}


void Time::add(long s) {
    seconden += s;
    berekenHMS();
}