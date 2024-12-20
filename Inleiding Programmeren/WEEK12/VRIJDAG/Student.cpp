#include "Student.h"
Student::Student(const string &voornaam, const string &achternaam, const string &rolnummer)
          : voornaam(voornaam),
            achternaam(achternaam),
            rolnummer(rolnummer) {
}

// getters
string Student::getVoornaam() const {
    return voornaam;
}
string Student::getAchternaam() const {
    return achternaam;
}
string Student::getRolnummer() const {
    return rolnummer;
}

string Student::toString() const {
    return voornaam + " " + achternaam + "(" + rolnummer + ")";
}