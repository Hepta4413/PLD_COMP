#include "Affectation.h"

Affectation::Affectation()
{
}

Affectation::Affectation(VarS var, long value, Type t)
{
	vars = var;
	valuei = value;
	type=t;
}

Affectation::Affectation(VarS var, char value)
{
	vars = var;
	valuec = value;
	type=CHAR;
}

Affectation::Affectation(VarTab var, long value, int i, Type t)
{
	vartab = var;
	valuei = value;
	index = i;
	type=t;
}

Affectation::Affectation(VarTab var, char value, int i)
{
	vartab = var;
	valuec = value;
	index = i;
	type=CHAR;
}

Affectation::Affectation(VarTab var, long* value, Type t)
{
	vartab = var;
	valuetabi = value;
	type=t;
}

Affectation::Affectation(VarTab var, char* value)
{
	vartab = var;
	valuetabc = value;
	type=CHAR;
}
