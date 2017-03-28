#include "VarS.h"

using namespace std;

VarS::VarS()
{
}

VarS::VarS(string* n, long val)
{
	nom=n;
	value=val;
}

VarS::VarS(long val)
{
    value=val;
}

VarS::VarS(string* n)
{
    nom=n;
}
