#ifndef G1-PROBLEME_H_INCLUDED
#define G1-PROBLEME_H_INCLUDED

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
    setVariables(std::vector<Variable> Variables);
    setContraintes(std::vector<Contrainte> Contraintes);
    setNoeud_initial(Noeud Noeud_initial);
};

#endif // G1-PROBLEME_H_INCLUDED
