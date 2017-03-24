#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "VarTab.h"
#include "VarS.h"
#include "Expression.h"

class Affectation : public Expression
{
	public:
	Affectation();
	Affectation(VarS vars, long value);
	Affectation(VarS vars, char value);
	Affectation(VarTab vartab, long value, int i);
	Affectation::Affectation(VarTab vartab, char value, int i);
	Affectation::Affectation(VarTab vartab, long value[], Type t);
	Affectation::Affectation(VarTab vartab, char value[]);
	
	private:
	VarS vars;
	VarTab vartab;
	long valuei;
	char valuec;
	int index;
		
};

#endif
