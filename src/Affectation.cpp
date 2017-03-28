#include "Affectation.h"

Affectation::Affectation()
{
}

Affectation::Affectation(Variable* var, Expression* value, Opbinaire op)

{
	vars = var;
	valuei = value;
  operateur=op;
}

Affectation::Affectation(VarTab* var, Expression* value, int i, Opbinaire op)
{
	vartab = var;
	valuei = value;
	index = i;
  operateur=op;
}
