#ifndef G1_ATTRIBUTION_H_INCLUDED
#define G1_ATTRIBUTION_H_INCLUDED
#include "G1-Variable.h"
class Attribution
{
    /*---Attributs---*/
private:
    Variable _Var;         // Variable attribué
    int _valeur;           // Valeur attribué

public:
    Attribution();
    Attribution(Variable var, int val);
    Attribution(const Attribution* attribution);
    ~Attribution(){}
    Variable getVar(){return _Var;};
    int getValeur(){return _valeur;};
    void setVariable(Variable var){_Var=var;};
    void setValeur(int val){_valeur=val;};
};

#endif // G1-ATTRIBUTION_H_INCLUDED
