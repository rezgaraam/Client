//
// Created by Rezgar Valizadeh on 03/02/2022.
//
#include "Variable.h"

/**
Retourne une copie de l'arbre repr�sentant f
*/
/*virtual*/ Expression * Variable::clone () const
{
    return new Variable;
}

///**
//Conversion de f en string
//*/
//virtual const string toString() const = 0;

/*virtual*/ Variable::operator string() const
{
    return "x";
}

/**
Calcule la valeur de f(x)
*/
/*virtual*/ double Variable::evaluer(const double & x) const
{
    return x;
}

