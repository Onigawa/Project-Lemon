#include <iostream>
#include "G1-Contrainte.h"

using namespace std;

bool Contrainte::isValable()
{
    switch(_Code)
    {
    case 0: ///Deux variables diff�rentes
    {
        if(_Variables[0]!=_Variables[1])
        {
            return true;
        }
        break;
    }

    case 1: ///Deux variables �gales
    {
        if(_Variables[0]==_Variables[1])
        {
            return true;
        }
        break;
    }

    case 2: ///Plusieurs variables 2 � 2 diff�rentes
    {

        unsigned int i,j;

        for(i=0; i<_Variables.size()-1; i++) ///parcours de 0 � n-1
        {
            for(j=i+1; j<_Variables.size(); j++) ///parcours de 1 � n
            {
                if(_Variables[i] == _Variables[j])///si deux valeurs sont identiques alors c'est faux
                {
                    return false;
                }
            }
        }

        return true;
        break;
    }

    case 3: ///Plusieurs variables 2 � 2 identiques
    {

        unsigned int i,j;

        for(i=0; i<_Variables.size()-1; i++) //parcours de 0 � n-1
        {
            for(j=i+1; j<_Variables.size(); j++) //parcours de 1 � n
            {
                if(_Variables[i] != _Variables[j])//si deux valeurs sont identiques alors c'est faux
                {
                    return false;
                }
            }
        }

        return true;
        break;
    }
    }
    return false;
}
