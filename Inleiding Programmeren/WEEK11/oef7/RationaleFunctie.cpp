#include "RationaleFunctie.h"
using namespace std;
#include <iostream>
RationaleFunctie::RationaleFunctie() {};
RationaleFunctie::RationaleFunctie(const string &naam, const VeeltermFunctie &teller, const VeeltermFunctie &noemer)
        : naam(naam),
          teller(teller),
          noemer(noemer) {
}

const string& RationaleFunctie::getNaam() const {
    return naam;
}

void RationaleFunctie::setNaam(const string &naam) {
    this->naam = naam;
}


const VeeltermFunctie& RationaleFunctie::getTeller() const {
    return teller;
}

void RationaleFunctie::setTeller(VeeltermFunctie teller) {
    this->teller = teller;
}

const VeeltermFunctie& RationaleFunctie::getNoemer() const {
    return noemer;
}

void RationaleFunctie::setNoemer(VeeltermFunctie noemer) {
    this->noemer = noemer;
}

//functies
string RationaleFunctie::toString() const {
    string resultaat = naam + "(x) = ";
    if (noemer.berekenFunctiewaarde(0) != 0) {
        if (teller.berekenFunctiewaarde(0) != 0) {
            resultaat += teller.toString();
        }
        if (resultaat != naam + "(x) = ") {
            resultaat += " / ";
        }
        resultaat += noemer.toString();
    }

    return resultaat.empty() ? "f(x) = 0" : resultaat;
}

double RationaleFunctie::berekenFunctiewaarde(double x) const {
    double tellerWaarde = teller.berekenFunctiewaarde(x);
    double noemerWaarde = noemer.berekenFunctiewaarde(x);

    if (noemerWaarde == 0) {
        cout << "Deze waarde ligt buiten het domein van de functie"  << endl;
        return false;
    }

    return tellerWaarde / noemerWaarde;
}