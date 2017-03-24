#include "VarS.h"

VarS::VarS()
{
}

VarS::VarS(std::string n, int64_t val, Type t)
{
	nom=n;
	valueint=val;
	type=t;
}

VarS::VarS(std::string n, char val)
{
	nom=n;
	valuechar=val;
	type=CHAR;
}
