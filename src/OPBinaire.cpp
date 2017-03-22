#include "OPBinaire.h"

OPBinaire::OPBinaire()
{
}

OPBinaire::OPBinaire(Expression e1, Expression e2, Opbinaire op)
{
	this.e1 = e1;
	this.e2 = e2;
	this.op = op;
}
