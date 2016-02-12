#ifndef G1-CONTRAINTE_H_INCLUDED
#define G1-CONTRAINTE_H_INCLUDED
class Contrainte
{
    /*---Attributs---*/
private:
    int _Identifiant;         // Identifiant unique de la contrainte
    int _Code;                // Code d'identification de la contrainte
    std::vector<int> _Variables;           // Vector de stockage des variables

    /*---Méthodes---*/
    /// Methodes optionnelles mais définies dans le cas où elles pourraient être utiles pour le projet

public:
    Contrainte(){}      // Constructeur
    Contrainte(const Contrainte* contrainte);
    Contrainte(int Identifiant,int Code, std::vector<int> Variables);
    ~Contrainte(){}      // Destructeur
};


#endif // G1-CONTRAINTE_H_INCLUDED
