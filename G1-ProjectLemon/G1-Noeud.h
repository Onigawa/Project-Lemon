#ifndef G1-NOEUD_H_INCLUDED
#define G1-NOEUD_H_INCLUDED
#include "Variable.h"

class Noeud
{
    /*---Attributs---*/
private:
    int _Identifiant;         // Identifiant unique de la Noeud
    std::vector<int> _Suivants;           // Vector de stockage des identifiants des noeuds suivants
    std::vector<Variable> _Variables; // Stockage des variables au moment du noeud

    /*---Méthodes---*/
    /// Methodes optionnelles mais définies dans le cas où elles pourraient être utiles pour le projet

public:
    Noeud(){}      // Constructeur
    Noeud(const Noeud* Noeud);
    Noeud(int Identifiant, std::vector<int> Suivants, std::vector<Variable> Variables);
    ~Noeud(){}      // Destructeur
};

#endif // G1-NOEUD_H_INCLUDED
