#ifndef OPBINAIRE_H
#define OPBINAIRE_H

#include "Enums.h"
#include "Expression.h"

class OPBinaire : public Expression
{
	private :
	OPBinaire();
	OPBinaire(Expression e1, Expression e2, Opbinaire op);
		
	public :
	Expression e1;
	Expression e2;
	Opbinaire op;
	
};

#endif


