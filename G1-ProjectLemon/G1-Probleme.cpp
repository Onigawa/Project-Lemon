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

void Probleme::addAttribution(Attribution att)
{
    _EAC.push_back(att);
}

void CreaNoeud(){

///On créé un noeud avec la variable 1
///On crée un premier suivant avec sa première valeur
///On crée un deuxième suivant ...
///si plus de suivant arret
}

std::vector<Attribution> Probleme::methode_triviale(std::vector<Attribution> EA_entree)
{
    bool Attribue=false;
    Variable varchoisie;
    std::vector<Attribution> EA_retour;


    if(true/*Est complet*/)
    {
        for(unsigned int i=0; i<_Contraintes.size();i++) ///On vérifie que pour chaque contrainte
        {
            if(_Contraintes[i].isValable())///Elle sont vérifiés
            {
                return EA_entree;  ///Si oui on retourne la solution
            }else
            {
            EA_retour.clear();
            return EA_retour; ///Si non on retourne echec
            }
        }
    }else
    {
        for(unsigned int i=0;i<_Variables.size();i++) ///On cherche une variable non attribue
        {
            Attribue=false;
            for(unsigned int j=0;j<EA_entree.size();i++)
            {
                if(_Variables[i].getIdentifiant()==EA_entree[j].getVar().getIdentifiant())
                {
                    Attribue=true;  ///Cette variable est deja attribuée
                    j=EA_entree.size(); //Debranchement
                }
            }
            if(Attribue==false)///La variable n'est pas attribuée
            {
                varchoisie=_Variables[i]; ///On la choisie
                i=_Variables.size(); //Debranchement
            }
        }
         if (Attribue==true) ///Si toutes les variables sont attribuées
         {
            EA_retour.clear();
            return EA_retour;
         }

        for(unsigned int i=0;i<varchoisie.getDomaine().size();i++) ///Pour tout le domaine de definition
        {
            int val=varchoisie.getDomaine()[i];
            Attribution att(varchoisie,val);
            EA_entree.push_back(att);
            EA_retour = methode_triviale(EA_entree);  ///Ea_retour=triviale(Ea_entree+"varchoisie=val")
        }

        if(!EA_retour.empty())
        {
            return EA_retour;
        }

    }
            EA_retour.clear();
            return EA_retour;
}
