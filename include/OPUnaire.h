#ifndef OPUNAIRE_H
#define OPUNAIRE_H

#include "Enums.h"
#include "Expression.h"

class OPUnaire : public Expression
{
	private :
	OPUnaire();
	OPUnaire(Expression e, Opunaire op);
		
	public :
	Expression exp;
	Opunaire op;
	
};

#endif

