#ifndef G1-CONTRAINTE_H_INCLUDED
#define G1-CONTRAINTE_H_INCLUDED
class Contrainte
{
    /*---Attributs---*/
private:
    int _Identifiant;         // Identifiant unique de la contrainte
    int _Code;                // Code d'identification de la contrainte
    std::vector<Variable> _Variables;           // Vector de stockage des variables

    /*---M�thodes---*/
    /// Methodes optionnelles mais d�finies dans le cas o� elles pourraient �tre utiles pour le projet

public:
    Contrainte(){}      // Constructeur
    Contrainte(const Contrainte* contrainte);
    Contrainte(int Identifiant,int Code, std::vector<int> Variables);
    ~Contrainte(){}      // Destructeur
    int getIdentifiant();
    int getCode();
    std::vector<Variable> getVariables();
    void setIdentifiant(int Identifiant);
    void setCode(int Code);
    void setVariables(std::vector<Variable> Variables);
};


#endif // G1-CONTRAINTE_H_INCLUDED