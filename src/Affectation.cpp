#include "Affectation.h"

Affectation::Affectation()
{
}

Affectation::Affectation(VarS var, long value, Opbinaire op)

{
	vars = var;
	valuei = value;
    operateur=op;
}

Affectation::Affectation(VarTab var, long value, int i, Opbinaire op)
{
	vartab = var;
	valuei = value;
	index = i;
    operateur=op;
}
