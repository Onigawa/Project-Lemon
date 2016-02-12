#ifndef G1_NOEUD_H_INCLUDED
#define G1_NOEUD_H_INCLUDED
#include "G1-Variable.h"
#include <vector>
class Noeud
{
    /*---Attributs---*/
private:
    int _Identifiant;         // Identifiant unique de la Noeud
    std::vector<Noeud> _Suivants;           // Vector de stockage des identifiants des noeuds suivants
    std::vector<Variable> _Variables; // Stockage des variables au moment du noeud


    /*---Méthodes---*/
    /// Methodes optionnelles mais définies dans le cas où elles pourraient être utiles pour le projet

public:
    static int nbrNoeud;
    Noeud(){_Identifiant=nbrNoeud;nbrNoeud++;}      // Constructeur
    Noeud(std::vector<Noeud> Suivants);
    Noeud(const Noeud* Noeud);
    Noeud(int Identifiant, std::vector<Noeud> Suivants, std::vector<Variable> Variables);
    ~Noeud(){}      // Destructeur

    void addSuivants(Noeud suivant);
};

#endif // G1-NOEUD_H_INCLUDED
