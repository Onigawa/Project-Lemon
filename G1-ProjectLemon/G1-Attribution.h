#ifndef G1_ATTRIBUTION_H_INCLUDED
#define G1_ATTRIBUTION_H_INCLUDED
#include "G1-Variable.h"
class Attribution
{
    /*---Attributs---*/
private:
    int _Var;         // Variable attribué
    int _valeur;           // Valeur attribué

public:
    Attribution();
    Attribution(int var, int val){_Var=var;_valeur=val;};
    Attribution(const Attribution* attribution);
    ~Attribution(){}
    int getVar(){return _Var;};
    int getValeur(){return _valeur;};
    void setVariable(int var){_Var=var;};
    void setValeur(int val){_valeur=val;};
};

#endif // G1-ATTRIBUTION_H_INCLUDED
