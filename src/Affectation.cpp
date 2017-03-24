#include "Affectation.h"

Affectation::Affectation()
{
}

Affectation::Affectation(VarS vars, long value, Opbinaire op)

{
	vars = var;
	valuei = value;
    operateur=op;
}

Affectation::Affectation(VarTab vartab, long value, int i, Opbinaire op)
{
	vartab = var;
	valuei = value;
	index = i;
    operateur=op;
}
