#include <string>
#include "VeeltermFunctie.h"
#ifndef RATIONALEFUNCTIE_H
#define RATIONALEFUNCTIE_H

using namespace std;

class RationaleFunctie {
public:
    RationaleFunctie();
    RationaleFunctie(const string &naam, const VeeltermFunctie &teller, const VeeltermFunctie &noemer);


    // getter
    const string & getNaam() const;

    const VeeltermFunctie& getNoemer() const;

    const VeeltermFunctie& getTeller() const;

    //setter
    void setNaam(const string &naam);
    void setNoemer(VeeltermFunctie noemer);
    void setTeller(VeeltermFunctie teller);

    //functies
    string toString() const;
    double berekenFunctiewaarde(double x) const;

private:
    string naam;
    VeeltermFunctie teller;
    VeeltermFunctie noemer;
};

#endif //RATIONALEFUNCTIE_H
