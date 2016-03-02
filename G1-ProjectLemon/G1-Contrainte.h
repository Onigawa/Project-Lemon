#ifndef G1_CONTRAINTE_H_INCLUDED
#define G1_CONTRAINTE_H_INCLUDED
#include <vector>
#include "G1-Attribution.h"
class Contrainte
{
    /*---Attributs---*/

private:
    int _Identifiant;         // Identifiant unique de la contrainte
    int _Code;                // Code d'identification de la contrainte
    std::vector<int> _Variables;           // Vector de stockage des variables
    static int nbrContrainte;

    /*---Méthodes---*/
    /// Methodes optionnelles mais définies dans le cas où elles pourraient être utiles pour le projet

public:

    Contrainte(){_Identifiant=nbrContrainte;nbrContrainte++;}      // Constructeur
    Contrainte(const Contrainte* contrainte);
    Contrainte(int Identifiant,int Code, std::vector<int> Variables);
    ~Contrainte(){}      // Destructeur
    int getIdentifiant();
    int getCode();
    std::vector<int> getVariables();
    void setIdentifiant(int Identifiant);
    void setCode(int Code);
    void setVariables(std::vector<int> Variables);
    bool isValable();
};


#endif // G1-CONTRAINTE_H_INCLUDED
