#include "VarS.h"

using namespace std;

VarS::VarS()
{
}

VarS::VarS(string* n, Expression* val)
{
	nom=n;
	value=val;
}

VarS::VarS(Expression* val)
{
    value=val;
}

VarS::VarS(string* n)
{
    nom=n;
}
