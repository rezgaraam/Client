//
//  Error.h
//  Client
//
//  Created by Rezgar Valizadeh on 01/02/2022.
//

#ifndef Error_h
#define Error_h
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
class Error
{
public:
    const static int LONGUERMESSAGE=100;
    char message[1+LONGUERMESSAGE];
    Error(){ strcpy(this->message,"Errrrror");}
    Error(const char * messageerror)
    {
        strcpy(this->message,"Errrrror");
        int l= strlen(messageerror);
        static int n=LONGUERMESSAGE-9;
        if (l<= n)
        {
            strcat(this->message,messageerror);
        }
        else
        {
            strncat(this->message,messageerror,n);
            this->message[LONGUERMESSAGE]='\0';
        }
    }
    operator string ()const
    {
        return string (this->message);
    }
    friend ostream & operator <<(ostream & out,const Error &e)
    {
        out<<(string)e;
        return out;
    }

};

#endif /* Error_h */
