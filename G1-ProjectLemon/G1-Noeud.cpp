#include <vector>
#include "G1-Noeud.h"
int Noeud::nbrNoeud=0;

void Noeud::addSuivants(Noeud suivant){

_Suivants.push_back(suivant);

}
