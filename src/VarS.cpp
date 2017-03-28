#include "VarS.h"

using namespace std;

VarS::VarS()
{
}

VarS::VarS(string* n, long val)
{
	nom=n;
	valueint=val;
}

VarS::VarS(long val)
{
    valueint=val;
}

VarS::VarS(string* n)
{
    nom=n;
}
