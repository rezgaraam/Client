//
// Created by Rezgar Valizadeh on 03/02/2022.
//

#ifndef CLIENT_CONSTANTE_H
#define CLIENT_CONSTANTE_H
#include "expression.h"
/**
Repr�sente la fonction : x |---> K o� K est une constante comme dans : x |---> 5 par exemple
*/
class Constante : public Expression
{
public:
    double valeur;	// valeur de la constante

/**

cr�e la fonction constante : x |---> valeur
*/
    Constante( const double & valeur);
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


#endif //CLIENT_CONSTANTE_H
