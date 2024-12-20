#include <string>
#include <vector>
using namespace std;
#ifndef VEELTERMFUNCTIE_H
#define VEELTERMFUNCTIE_H

class VeeltermFunctie {
public:
    // constructor
    VeeltermFunctie(const string &naam, const vector<int> &coefficienten);
    VeeltermFunctie();

    // getter
    const string & getNaam() const;
    int getGraad() const;

    // setter
    void setNaam(const string &naam);
    void setCoefficienten(const vector<int> &coefficienten);

    // functies
    string toString() const;
    double berekenFunctiewaarde(double x) const;
    VeeltermFunctie berekenAfgeleide() const;
private:
    string naam;
    vector<int> coefficienten;

};

#endif //VEELTERMFUNCTIE_H
