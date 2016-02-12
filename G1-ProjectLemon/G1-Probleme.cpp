#include <vector>
#include "G1-Probleme.h"

std::vector<int> Probleme::SearchContrainteVariable(const int &Achercher) // Renvoi vecteur contenant les identifiants de toute les contraintes concernant la variable donnée
{
    vector<int> Resultat;
    for(unsigned int i=0; i<_Contraintes.size(); i++)
    {
        for(unsigned int j=0; j<_Contraintes[i].getVariable.size(); i++)
        {
            if(_Contraintes[i].getVariable[j]==Achercher)
            {
                Resultat.push_back(i);
            }
        }
    }
    return Resultat;
}
