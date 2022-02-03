//
// Created by Rezgar Valizadeh on 03/02/2022.
//
#include <sstream>
using namespace std;

#include "OpBinaire.h"

OpBinaire::OpBinaire( Expression * operandeGauche,  Expression * operandeDroit):gauche(operandeGauche),droit(operandeDroit){}
OpBinaire::OpBinaire( const OpBinaire & opBinaire):gauche(opBinaire.gauche->clone()), droit(opBinaire.droit->clone()){}
OpBinaire::~OpBinaire(void)
{
    delete gauche; delete droit;
    gauche = droit = NULL;
}



///**
//Conversion de f en string
//*/
//virtual const string toString() const = 0;

OpBinaire::operator string() const
{
    ostringstream oss;
    oss << '(' << gauche << symbole() << droit << ')';		// il y a parfois des parenth�ses superflues : cela reste � g�rer
    return oss.str();

}

/**
Calcule la valeur de f(x)
*/
double OpBinaire::evaluer(const double & x) const
{
    return effectuer(gauche->evaluer(x),droit->evaluer(x));
}




