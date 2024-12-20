#include <string>
#include <map>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H


class Student {
public:
    Student(const string &voornaam, const string &achternaam, const string &rolnummer);

    // getters
    string getVoornaam() const;
    string getAchternaam() const;
    string getRolnummer() const;


    // functies
    string toString() const;
    int getStudiePunten() const;
    bool schrijfIn(Cursus* cursus);
    bool schrijfUit(Cursus* cursus);
private:
    string voornaam;
    string achternaam;
    string rolnummer;
    int studiepunten;
    map <string, Cursus*> cursussen;

};



#endif //STUDENT_H
