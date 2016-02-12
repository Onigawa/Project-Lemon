#include "G1-Probleme.h"

#include <iostream>
#include <fstream>

using namespace std;

void Probleme::chargement()
{
    int identifiant,code, variable;
    string mon_fichier = "Probleme.txt";
    ifstream fichier(mon_fichier.c_str(), ios::in);
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
