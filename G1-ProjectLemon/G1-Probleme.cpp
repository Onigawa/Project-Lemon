#include <vector>
#include "G1-Probleme.h"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

std::vector<Variable> Probleme::getVariables()
{
    return _Variables;
}
std::vector<Contrainte> Probleme::getContraintes()
{
    return _Contraintes;
}
Noeud Probleme::getNoeud_initial()
{
    return _Noeud_initial;
}
void Probleme::setVariables(std::vector<Variable> Variables)
{
    _Variables = Variables;
}
void Probleme::setContraintes(std::vector<Contrainte> Contraintes)
{
    _Contraintes = Contraintes;
}
void Probleme::setNoeud_initial(Noeud Noeud_initial)
{
    _Noeud_initial = Noeud_initial;
}
std::vector<int> Probleme::SearchContrainteVariable(const int &Achercher) // Renvoi vecteur contenant les identifiants de toute les contraintes concernant la variable donnée
{
    std::vector<int> Resultat;
    for(unsigned int i=0; i<_Contraintes.size(); i++)
    {
        for(unsigned int j=0; j<_Contraintes[i].getVariables().size(); i++)
        {
            if(_Contraintes[i].getVariables()[j]==Achercher)
            {
                Resultat.push_back(i);
            }
        }
    }
    return Resultat;
}
void Probleme::chargement()
{
    int identifiant,code, variable;
    std::string mon_fichier = "Probleme.txt";
    std::ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)
    {
        int nbcontrainte;
        fichier >> nbcontrainte;
        cout << nbcontrainte << endl;
        for(int i=0; i<nbcontrainte; i++)
        {
            fichier >> identifiant;
            cout << identifiant << " ";
            fichier >> code;
            cout << code << " ";
            do
            {
                fichier >> variable;

                if(variable != -1)
                {
                    cout << variable << " ";
                    //mettre la variable quelque part
                }
            }
            while(variable != -1);
            cout << endl;
        }

        int nbvariable,domaine;
        fichier >> nbvariable;
        cout << nbvariable << endl;
        for(int i=0; i<nbvariable; i++)
        {
            fichier >> variable;
            cout << variable << " ";
            do
            {
                fichier >> domaine;

                if(domaine != -1)
                {
                    cout << domaine << " ";
                    //mettre la valeur du domaine quelque part
                }
            }while(domaine != -1);
            cout << endl;

        }

        fichier.close();
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;

    return;
}


void CreaNoeud(){

///On créé un noeud avec la variable 1
Noeud initial;

///On crée un premier suivant avec sa première valeur
///On crée un deuxième suivant ...
///si plus de suivant arret
}
