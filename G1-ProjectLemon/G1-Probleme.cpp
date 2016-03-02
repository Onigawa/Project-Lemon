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
std::vector<Contrainte> Probleme::SearchContrainteVariable(const int &Achercher) // Renvoi vecteur contenant les identifiants de toute les contraintes concernant la variable donnée
{
    std::vector<Contrainte> Resultat;
    for(unsigned int i=0; i<_Contraintes.size(); i++)
    {
        for(unsigned int j=0; j<_Contraintes[i].getVariables().size(); i++)
        {
            if(_Contraintes[i].getVariables()[j]==Achercher)
            {
                Resultat.push_back(_Contraintes[i]);
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
    std::vector<int> Var;
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
                    Var.push_back(variable);
                    cout << variable << " ";
                    //mettre la variable quelque part
                }
            }
            while(variable != -1);
            Contrainte(identifiant,code,Var);
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
            }
            while(domaine != -1);
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

void CreaNoeud()
{

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


    if(isComplet())
    {
        for(unsigned int i=0; i<_Contraintes.size(); i++) ///On vérifie que pour chaque contrainte
        {
            if(isValable(EA_entree,_Contraintes[i]))///Elle sont vérifiés
            {
                return EA_entree;  ///Si oui on retourne la solution
            }
            else
            {
                EA_retour.clear();
                return EA_retour; ///Si non on retourne echec
            }
        }
    }
    else
    {
        for(unsigned int i=0; i<_Variables.size(); i++) ///On cherche une variable non attribue
        {
            Attribue=false;
            for(unsigned int j=0; j<EA_entree.size(); i++)
            {
                if(_Variables[i].getIdentifiant()==EA_entree[j].getVar())
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

        for(unsigned int i=0; i<varchoisie.getDomaine().size(); i++) ///Pour tout le domaine de definition
        {
            int val=varchoisie.getDomaine()[i];
            int var=varchoisie.getIdentifiant();
            Attribution att(var,val);
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


bool Probleme::isComplet()
{
    unsigned int j=0;
    for(unsigned int i=0; i<_Variables.size(); i++)
    {
        for(j=0; j<_EAC.size(); j++)
        {
            if(_Variables[i].getIdentifiant()==_EAC[j].getVar())
            {
                j=_EAC.size()+1;
            }
        }
        if(j==_EAC.size())
        {
            return false;
        }
    }
    return true;
}

std::vector<Attribution> Probleme::methode_reduction_domaine(std::vector<Attribution> EA_entree,std::vector<Variable> DVC_entree)
{
    {
        bool Attribue=false;
        Variable varchoisie;
        std::vector<Attribution> EA_retour;


        if(isComplet())
        {
            return EA_entree;
        }
        else
        {
            for(unsigned int i=0; i<_Variables.size(); i++) ///On cherche une variable non attribue
            {
                Attribue=false;
                for(unsigned int j=0; j<EA_entree.size(); i++)
                {
                    if(_Variables[i].getIdentifiant()==EA_entree[j].getVar())
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

            for(unsigned int i=0; i<varchoisie.getDomaine().size(); i++) ///Pour tout le domaine de definition
            {
                int val=varchoisie.getDomaine()[i];
                int var=varchoisie.getIdentifiant();
                Attribution att(var,val);
                EA_entree.push_back(att);
                DVC_entree=reduction_domaine(DVC_entree,att); ///On réduit le domaine
                EA_retour = methode_reduction_domaine(EA_entree,DVC_entree);  ///Ea_retour=methode(Ea_entree+"varchoisie=val") avec domaine reduit
            }

            if(!EA_retour.empty())
            {
                return EA_retour;
            }

        }
        EA_retour.clear();
        return EA_retour;
    }
}

std::vector<Variable> Probleme::reduction_domaine(std::vector<Variable> origine,Attribution att)
{

    std::vector<Contrainte> contraintes;
    contraintes =SearchContrainteVariable(att.getVar()); ///On recupère les contraintes concernées
    std::vector<int> tempo;
    std::vector<int> domaine;

    for(unsigned int j=0; j<contraintes.size(); j++) ///Block de supression de la variable de travail pour simplifier les calculs futurs (la supression se fait en local donc pas de supression définitive)
    {
        for(unsigned int k=0; k<contraintes[j].getVariables().size(); k++)
        {
            if(contraintes[j].getVariables()[k]==att.getVar())
            {
                tempo =contraintes[j].getVariables();
                tempo.erase(tempo.begin()+k);
                contraintes[j].setVariables(tempo);
            }
        }

    }

    for(unsigned int i=0; i<contraintes.size(); i++)
    {

        Contrainte contrainteactuelle =contraintes[i];
        Variable var0 =searchVariable(contrainteactuelle.getVariables()[0],origine);
        switch(contrainteactuelle.getCode())
        {
        case 0:
        {
            for(unsigned int j=0; j<origine.size(); j++) ///Pour chaque variable
            {
                if(origine[j].getIdentifiant()==var0.getIdentifiant()) ///si on tombe sur la variable complémentaire de celle de l'attribution
                {
                    domaine=origine[j].getDomaine(); ///on extrait son domaine
                    for(unsigned int k=0; k<domaine.size(); k++) ///pour tout son domaine
                    {
                        if (att.getValeur()==domaine[k]) ///On cherche si la valeur est présente
                        {
                            domaine.erase(tempo.begin()+k);///Si oui on la supprime
                        }
                    }
                    origine[j].setDomaine(domaine);/// et on update son domaine
                }

            }
        }
        break;
        case 1:
        {
            for(unsigned int j=0; j<origine.size(); j++) ///Pour chaque variable
            {
                if(origine[j].getIdentifiant()==var0.getIdentifiant()) ///si on tombe sur la variable complémentaire de celle de l'attribution
                {
                    domaine=origine[j].getDomaine(); ///on extrait son domaine
                    for(unsigned int k=0; k<domaine.size(); k++) ///pour tout son domaine
                    {
                        if (att.getValeur()!=domaine[k]) ///On cherche si une autre valeur est présente
                        {
                            domaine.erase(tempo.begin()+k);///Si oui on la supprime
                        }
                    }
                    origine[j].setDomaine(domaine);/// et on update son domaine
                }

            }

        }
        break;

        case 2:
        {
            for(unsigned int j=0; j<origine.size(); j++) ///Pour chaque variable
            {
                for(unsigned int l=0; l<contrainteactuelle.getVariables().size(); l++)
                {
                    var0 =searchVariable(contrainteactuelle.getVariables()[l],origine);
                    if(origine[j].getIdentifiant()==var0.getIdentifiant()) ///si on tombe sur la variable complémentaire de celle de l'attribution
                    {
                        domaine=origine[j].getDomaine(); ///on extrait son domaine
                        for(unsigned int k=0; k<domaine.size(); k++) ///pour tout son domaine
                        {
                            if (att.getValeur()==domaine[k]) ///On cherche si la valeur est présente
                            {
                                domaine.erase(tempo.begin()+k);///Si oui on la supprime
                            }
                        }
                        origine[j].setDomaine(domaine);/// et on update son domaine
                    }
                }

            }
        }
        break;
        case 3:
        {
            for(unsigned int j=0; j<origine.size(); j++) ///Pour chaque variable
            {
                for(unsigned int l=0; l<contrainteactuelle.getVariables().size(); l++)
                {
                    var0 =searchVariable(contrainteactuelle.getVariables()[l],origine);
                    if(origine[j].getIdentifiant()==var0.getIdentifiant()) ///si on tombe sur la variable complémentaire de celle de l'attribution
                    {
                        domaine=origine[j].getDomaine(); ///on extrait son domaine
                        for(unsigned int k=0; k<domaine.size(); k++) ///pour tout son domaine
                        {
                            if (att.getValeur()!=domaine[k]) ///On cherche si une autre valeur est présente
                            {
                                domaine.erase(tempo.begin()+k);///Si oui on la supprime
                            }
                        }
                        origine[j].setDomaine(domaine);/// et on update son domaine
                    }
                }

            }
        }
        break;
        }
    }
    return origine;
}

Variable Probleme::searchVariable (int identifiant)
{
    for(unsigned int i =0; i<_Variables.size(); i++)
    {
        if(_Variables[i].getIdentifiant()==identifiant)
            return _Variables[i];
    }
    cout <<endl << "Variable non trouvee"<<endl;
    return _Variables[0];
}

Variable Probleme::searchVariable (int identifiant,std::vector<Variable> origine)
{
    for(unsigned int i =0; i<origine.size(); i++)
    {
        if(origine[i].getIdentifiant()==identifiant)
            return origine[i];
    }
    cout <<endl << "Variable non trouvee"<<endl;
    return _Variables[0];
}

int Probleme::searchValVarAtt(std::vector<Attribution> att,int Var)
{
    for(unsigned int i=0; i<att.size(); i++)
    {
        if(att[i].getVar()==Var)
        {
            return att[i].getValeur();
        }
    }
    ///Variable non trouvee
    return -1;
}

bool Probleme::isAttribue(std::vector<Attribution> att,int Var)
{
    for(unsigned int i=0; i<att.size(); i++)
    {
        if(att[i].getVar()==Var)
        {
            return true;
        }
    }
    return false;
}


bool Probleme::isValable(std::vector<Attribution> att, Contrainte cont)
{
    switch(cont.getCode())
    {
    case 0: ///Deux variables différentes
    {
        if(!isAttribue(att,cont.getVariables()[0])||!isAttribue(att,cont.getVariables()[1]))  ///Si l'une n'est pas attribue la contrainte est forcément respecté
        {
            return true;
        }


        if(searchValVarAtt(att,cont.getVariables()[0])!=searchValVarAtt(att,cont.getVariables()[1]))
        {
            return true;
        }


        break;
    }

    case 1: ///Deux variables égales
    {
        if(!isAttribue(att,cont.getVariables()[0])||!isAttribue(att,cont.getVariables()[1]))  ///Si l'une n'est pas attribue la contrainte est forcément respecté
        {
            return true;
        }
        if(searchValVarAtt(att,cont.getVariables()[0])==searchValVarAtt(att,cont.getVariables()[1]))
        {
            return true;
        }
        break;
    }

    case 2: ///Plusieurs variables 2 à 2 différentes
    {

        unsigned int i,j;

        for(i=0; i<cont.getVariables().size()-1; i++) ///parcours de 0 à n-1
        {
            while(!isAttribue(att,cont.getVariables()[i])||i>=cont.getVariables().size()-1) ///On verifie que la variable est attribué
            {
                i++; /// Si elle ne l'est pas on passe a la suivante
            };

            for(j=i+1; j<cont.getVariables().size(); j++) ///parcours de 1 à n
            {
                while(!isAttribue(att,cont.getVariables()[j])||j>=cont.getVariables().size()) ///On verifie que la variable est attribué
                {
                    j++; /// Si elle ne l'est pas on passe a la suivante
                };

                if(searchValVarAtt(att,cont.getVariables()[i])==searchValVarAtt(att,cont.getVariables()[j]))///si deux valeurs sont identiques alors c'est faux
                {
                    return false;
                }
            }
        }

        return true;
        break;
    }

    case 3: ///Plusieurs variables 2 à 2 identiques
    {


        unsigned int i,j;

        for(i=0; i<cont.getVariables().size()-1; i++) ///parcours de 0 à n-1
        {
            while(!isAttribue(att,cont.getVariables()[i])||i>=cont.getVariables().size()-1) ///On verifie que la variable est attribué
            {
                i++; /// Si elle ne l'est pas on passe a la suivante
            };
            for(j=i+1; j<cont.getVariables().size(); j++) ///parcours de 1 à n
            {
               while(!isAttribue(att,cont.getVariables()[j])||j>=cont.getVariables().size()) ///On verifie que la variable est attribué
                {
                    j++; /// Si elle ne l'est pas on passe a la suivante
                };
                if(searchValVarAtt(att,cont.getVariables()[i])!=searchValVarAtt(att,cont.getVariables()[j]))///si deux valeurs sont identiques alors c'est faux
                {
                    return false;
                }
            }
        }

        return true;
        break;
    }

    }
    return false; ///Code non reconnu
}

