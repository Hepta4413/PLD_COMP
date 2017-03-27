#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "VarTab.h"
#include "VarS.h"
#include "Expression.h"

class Affectation : public Expression
{
	public:
	Affectation();
	Affectation(VarS* vars, long value,Opbinaire* op);
	Affectation(VarTab* vartab, long value, int i, Opbinaire* op);
	
	protected:
	VarS* vars;
	VarTab* vartab;
	long valuei;
	int index;
	Opbinaire* operateur;
		
};

#endif
