#include "VarS.h"

VarS::VarS()
{
}

VarS::VarS(std::string* n, long val)
{
	nom=n;
	valueint=val;
	type=t;
}

VarS::VarS(long val)
{
    valueint=val;
}

VarS::VarS(std::string* n)
{
    nom=n;
}
