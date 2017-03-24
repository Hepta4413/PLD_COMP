#include "Affectation.h"

Affectation::Affectation()
{
}

Affectation::Affectation(VarS vars, long value, Opbinaire op)
{
	this.vars = vars;
	valuei = value;
	type=t;
    operateur=op;
}

Affectation::Affectation(VarTab vartab, long value, int i, Opbinaire op)
{
	this.vartab = vartab;
	valuei = value;
	index = i;
	type=t;
    operateur=op;
}


