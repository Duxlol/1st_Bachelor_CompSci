#include "Audiobestand.h"
#include "Time.h"
#include <iostream>
Audiobestand::Audiobestand() {};
Audiobestand::Audiobestand(const string &titel, long duur, const string &uitvoerder)
        : titel(titel),
          duur(duur),
          uitvoerder(uitvoerder) {
}


long Audiobestand::getDuur() const {
    return duur;
}

const string & Audiobestand::getTitel() const {
    return titel;
}

const string & Audiobestand::getUitvoerder() const {
    return uitvoerder;
}

void Audiobestand::setDuur(long duur) {
    Audiobestand::duur = duur;
}

void Audiobestand::setTitel(const string &titel) {
    Audiobestand::titel= titel;
}

void Audiobestand::setUitvoerder(const string &uitvoerder) {
    Audiobestand::uitvoerder = uitvoerder;
}

void Audiobestand::toonInfo() {
    Time tijd(duur);
    cout<<getTitel() + " - " + getUitvoerder() + " - " + tijd.toString()<<endl;
}

string Audiobestand::toString() {
    return "";
}

void Audiobestand::stop() {
    cout << "Stoppen van " << getTitel() << endl;
}

void Audiobestand::speelAf() {
    cout << "Afspelen van " << getTitel() << endl;
}