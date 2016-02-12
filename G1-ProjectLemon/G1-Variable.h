#ifndef G1-VARIABLE_H_INCLUDED
#define G1-VARIABLE_H_INCLUDED

class Variable
{
    /*---Attributs---*/
private:
    int _Identifiant;         // Identifiant unique de la Variable
    std::vector<int> _Domaine;           // Vector de stockage du domaine de definition

    /*---M�thodes---*/
    /// Methodes optionnelles mais d�finies dans le cas o� elles pourraient �tre utiles pour le projet

public:
    Variable(){}      // Constructeur
    Variable(const Variable* Variable);
    Variable(int Identifiant, std::vector<int> Domaine);
    ~Variable(){}      // Destructeur
    int getIdentifiant();
    std::vector<int> getDomaine();
    void setIdentifiant(int);
    void setDomaine(std::vector<int>);
};
#endif // G1-VARIABLE_H_INCLUDED
