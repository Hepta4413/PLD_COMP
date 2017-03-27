#include "OPBinaire.h"

OPBinaire::OPBinaire()
{
}

OPBinaire::OPBinaire(Expression* ex1, Expression* ex2, Opbinaire ope)
{
	e1 = ex1;
	e2 = ex2;
	op = ope;
}
