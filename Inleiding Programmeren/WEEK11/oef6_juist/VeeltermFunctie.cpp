#include "VeeltermFunctie.h"
#include <cmath>
#include <iostream>
using namespace std;


// constructor
VeeltermFunctie::VeeltermFunctie(const string &naam, const vector<int> &coefficienten): naam(naam),coefficienten(coefficienten) {}
VeeltermFunctie::VeeltermFunctie() {}


//getter
const string & VeeltermFunctie::getNaam() const {
    return naam;
}

int VeeltermFunctie::getGraad() const {
    for (int i = coefficienten.size() -1; i >= 0; i--) {
        if (coefficienten[i] != 0) {
            return i;
        }
    }
    return -1;
}


//setter
void VeeltermFunctie::setNaam(const string &naam) {
    this->naam = naam;
}
void VeeltermFunctie::setCoefficienten(const vector<int> &coefficienten) {
    this->coefficienten = coefficienten;
}

//functies
string VeeltermFunctie::toString() const {
    bool EersteTerm = true;
    string resultaat = naam + "(x) = ";

    for (int i = coefficienten.size() - 1; i >= 0; i--) {
        if (coefficienten[i] != 0) {
            if (EersteTerm == false)
                resultaat += (coefficienten[i] > 0) ? " + " : " - ";
            else if (coefficienten[i] < 0)
                resultaat += "-";

            if (i == 0) {
                resultaat += to_string(abs(coefficienten[i])); // constant term
            } else if (i==1) {
                resultaat += to_string(abs(coefficienten[i]))+" x";
            }

            else {
                resultaat += to_string(abs(coefficienten[i])) + " x^" + to_string(i); // other terms
            }
            EersteTerm = false;
        }
    }

    return resultaat.empty() ? "f(x) = 0" : resultaat;
}



double VeeltermFunctie::berekenFunctiewaarde(double x) const {
    int resultaat = 0;
    for (int i = 0; i< coefficienten.size();i++) {
        resultaat += coefficienten[i] * pow(x,i);
    }
    return resultaat;
}

VeeltermFunctie VeeltermFunctie::berekenAfgeleide() const {
    vector<int> AfgeleideCoeffs;

    for (int i = 1; i < coefficienten.size(); i++) {
        AfgeleideCoeffs.push_back(coefficienten[i] * i);
    }

    if (AfgeleideCoeffs.empty()) {
        AfgeleideCoeffs.push_back(0);
    }

    VeeltermFunctie afgeleide;

    // Check if the name already ends with an apostrophe
    if (naam.back() == '\'') {
        afgeleide.setNaam(naam);  // If it already has a prime, use the original name
    } else {
        afgeleide.setNaam(naam + "'");  // Otherwise, add a prime
    }

    afgeleide.setCoefficienten(AfgeleideCoeffs);

    return afgeleide;
}

