//
// Created by Rezgar Valizadeh on 03/02/2022.
//
#include "Expression.h"

/*virtual*/ Expression:: ~Expression(void){}

ostream & operator << ( ostream & os, const Expression * expression) {
    return os << (string) (*expression);
}
