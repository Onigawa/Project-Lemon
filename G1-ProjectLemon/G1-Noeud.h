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


    /*---M�thodes---*/
    /// Methodes optionnelles mais d�finies dans le cas o� elles pourraient �tre utiles pour le projet

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
