#include <vector>
#include "G1-Variable.h"
int Variable::nbrVariable=0;

int Variable::getIdentifiant()
{
    return _Identifiant;
}
std::vector<int> Variable::getDomaine()
{
    return _Domaine;
}
void Variable::setIdentifiant(int Identifiant)
{
    _Identifiant = Identifiant;
}
void Variable::setDomaine(std::vector<int> Domaine)
{
    _Domaine = Domaine;
}
