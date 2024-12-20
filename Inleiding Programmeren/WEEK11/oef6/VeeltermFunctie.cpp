#include "VeeltermFunctie.h"
#include <cmath>
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
    string resultaat = "f(x) = ";
    for (int i = coefficienten.size()-1; i >= 0; i--) {
        if (coefficienten[i] != 0) {
            if (EersteTerm == false) resultaat += (coefficienten[i] > 0) ? " + " : " - ";
            resultaat += (i==0) ? to_string(abs(coefficienten[i])) : to_string(abs(coefficienten[i]) + "x^" + to_string(i));
            EersteTerm = false;
        }
    }

    return resultaat.empty ? "f(x) = 0" : resultaat;
}

double VeeltermFunctie::berekenFunctiewaarde(double x) const {
    int resultaat = 0;
    for (int i = coefficienten.size()-1; i>0; i++) {
        resultaat += coefficienten[i] * pow(x,i);
    }
    return resultaat;
}

VeeltermFunctie VeeltermFunctie::berekenAfgeleide() const {
    vector<int> AfgeleideCoeffs;

    for (int i = 1; i < coefficienten.size(); i++) {
        AfgeleideCoeffs.push_back(coefficienten[i] * i);
    }
    VeeltermFunctie afgeleide;
    afgeleide.setNaam(naam+"`");
    return afgeleide;
}