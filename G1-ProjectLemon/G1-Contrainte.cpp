#include <iostream>
#include "G1-Contrainte.h"
#include <vector>
#include "G1-Variable.h"

using namespace std;
int Contrainte::nbrContrainte=0;

int Contrainte::getIdentifiant()
{
    return _Identifiant;
}
int Contrainte::getCode()
{
    return _Code;
}
std::vector<int> Contrainte::getVariables()
{
    return _Variables;
}
void Contrainte::setIdentifiant(int Identifiant)
{
    _Identifiant = Identifiant;
}
void Contrainte::setCode(int Code)
{
    _Code = Code;
}
void Contrainte::setVariables(std::vector<int> Variables)
{
    _Variables = Variables;
}


bool Contrainte::isValable()
{
    switch(_Code)
    {
    case 0: ///Deux variables différentes
    {
        if(_Variables[0]!=_Variables[1])
        {
            return true;
        }
        break;
    }

    case 1: ///Deux variables égales
    {
        if(_Variables[0]==_Variables[1])
        {
            return true;
        }
        break;
    }

    case 2: ///Plusieurs variables 2 à 2 différentes
    {

        unsigned int i,j;

        for(i=0; i<_Variables.size()-1; i++) ///parcours de 0 à n-1
        {
            for(j=i+1; j<_Variables.size(); j++) ///parcours de 1 à n
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

    case 3: ///Plusieurs variables 2 à 2 identiques
    {

        unsigned int i,j;

        for(i=0; i<_Variables.size()-1; i++) //parcours de 0 à n-1
        {
            for(j=i+1; j<_Variables.size(); j++) //parcours de 1 à n
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



