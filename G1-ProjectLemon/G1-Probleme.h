#ifndef G1_PROBLEME_H_INCLUDED
#define G1_PROBLEME_H_INCLUDED
#include "G1-Contrainte.h"
#include "G1-Variable.h"
#include "G1-Noeud.h"
class Probleme
{
    /*---Attributs---*/
private:
    std::vector<Variable> _Variables;           // Vector des variables initiales
    std::vector<Contrainte> _Contraintes;           // Vector des Contrainte initiales
    Noeud _Noeud_initial;    //Noeud de débur de l'arbre de recherche

    /*---Méthodes---*/
    /// Methodes optionnelles mais définies dans le cas où elles pourraient être utiles pour le projet

public:
    Probleme(){}      // Constructeur
    Probleme(const Probleme* Probleme);
    Probleme(int Identifiant, std::vector<int> Domaine);
    ~Probleme(){}      // Destructeur
    std::vector<Variable> getVariables();
    std::vector<Contrainte> getContraintes();
    Noeud getNoeud_initial();
    void setVariables(std::vector<Variable> Variables);
    void setContraintes(std::vector<Contrainte> Contraintes);
    void setNoeud_initial(Noeud Noeud_initial);
    void chargement();

    std::vector<int> SearchContrainteVariable(const int &Achercher);
};

#endif // G1-PROBLEME_H_INCLUDED
