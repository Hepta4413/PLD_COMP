#include "VarS.h"
#include <iostream>

using namespace std;

VarS::VarS()
{
}

VarS::VarS(string* n)
{
    nom=n;
    VerifDeclaration(nom);
}
