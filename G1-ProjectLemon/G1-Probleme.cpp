#include "G1-Probleme.h"
#include <iostream>
#include <fstream>
using namespace std;

void Probleme::chargement()
{
    string mon_fichier = "Probleme.txt";
    ifstream fichier(mon_fichier.c_str(), ios::in);
    if(fichier)
    {
        int nbcontrainte;
        fichier >> nbcontrainte;
        cout << nbcontrainte;
        fichier.close();
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;

    return;
}
