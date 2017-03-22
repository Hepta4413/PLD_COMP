#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "VarTab.h"
#include "VarS.h"
#include "Expression.h"

class Affectation : public Expression
{
	public:
	Affectation();
	Affectation(VarS vars, int64_t value);
	Affectation(VarS vars, char value);
	Affectation(VarTab vartab, int64_t value, int i);
	
	private:
	VarS vars;
	VarTab vartab
	int64_t valuei;
	char valuec;
	int index;
		
};

#endif
