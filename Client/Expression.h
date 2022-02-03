//
// Created by Rezgar Valizadeh on 03/02/2022.
//

#ifndef CLIENT_EXPRESSION_H
#define CLIENT_EXPRESSION_H
#include <iostream>
#include <string>

using namespace std;

/**

Represente une fonction math�matique reelle e une variable reelle, autrement dit une fonction f de la forme :

x |---> f(x)		oe x et f(x) sont des nombres reels

Evidemment en machine, f est representee par un arbre

*/
class Expression
{
public:
/**
Efface l'arbre repr�sentant f
*/
    virtual ~Expression(void);

/**
Retourne une copie de l'arbre representant f
*/
    virtual Expression * clone () const = 0;

    virtual operator string() const = 0;

/**
Calcule la valeur de f(x)
*/
    virtual double evaluer(const double & x) const = 0;
};

ostream & operator << ( ostream & os, const Expression * expression);
#endif //CLIENT_EXPRESSION_H
