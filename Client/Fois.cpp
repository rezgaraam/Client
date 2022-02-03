//
// Created by Rezgar Valizadeh on 03/02/2022.
//

#include "Fois.h"

Fois::Fois( Expression * operandeGauche,  Expression * operandeDroit):OpBinaire(operandeGauche,operandeDroit){}
Fois::Fois( const Fois & fois):OpBinaire(fois){}

/**
Retourne une copie de l'arbre repr�sentant f
*/
/*virtual*/ Expression * Fois::clone () const
{
    return new Fois(*this);
}

/**
retourne le symbole de l'op�rateur : '*'
*/
/*virtual*/ char Fois::symbole() const
{
    return '*';
}

/**
repr�sente le calcul � effectuer :
retourne x * y
*/
/*virtual*/ double Fois::effectuer(const double & x, const double & y) const
{
    return x * y;
}