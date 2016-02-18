#ifndef G1_PROBLEME_H_INCLUDED
#define G1_PROBLEME_H_INCLUDED
#include "G1-Contrainte.h"
#include "G1-Variable.h"
#include "G1-Noeud.h"
#include "G1-Attribution.h"
class Probleme
{
    /*---Attributs---*/
private:
    std::vector<Variable> _Variables;           // Vector des variables initiales
    std::vector<Contrainte> _Contraintes;           // Vector des Contrainte initiales
    Noeud _Noeud_initial;    //Noeud de débur de l'arbre de recherche
    std::vector<Attribution> _EAC; //Ensemble des Attribution en cours

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
    void addAttribution(Attribution att);

    std::vector<Contrainte> SearchContrainteVariable(const int &Achercher);
    std::vector<Attribution> methode_triviale(std::vector<Attribution> EA_entree);
    std::vector<Attribution> methode_reduction_domaine(std::vector<Attribution> EA_entree,std::vector<Variable> DVC_entree);
    bool isComplet();
    std::vector<Variable> reduction_domaine(std::vector<Variable> origine,Attribution att);
    Variable searchVariable (int identifiant);
    Variable searchVariable (int identifiant,std::vector<Variable> origine);
};

#endif // G1-PROBLEME_H_INCLUDED
