//
// Created by Rezgar Valizadeh on 03/02/2022.
//

#ifndef CLIENT_VARIABLE_H
#define CLIENT_VARIABLE_H
#include "expression.h"

/**
Repr�sente la fonction math�matique : x |---> x

*/
class Variable : public Expression
{
public:

/**
Retourne une copie de l'arbre repr�sentant f
*/
    virtual Expression * clone () const;

    virtual operator string() const;

/**
Calcule la valeur de f(x)
*/
    virtual double evaluer(const double & x) const;
};


#endif //CLIENT_VARIABLE_H
