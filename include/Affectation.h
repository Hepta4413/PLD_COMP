#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "VarTab.h"
#include "VarS.h"
#include "Expression.h"

class Affectation : public Expression
{
	public:
	Affectation();
	Affectation(VarS vars, long value, Type t);
	Affectation(VarS vars, char value);
	Affectation(VarTab vartab, long value, int i, Type t);
	Affectation(VarTab vartab, char value, int i);
	Affectation(VarTab vartab, long* value, Type t);
	Affectation(VarTab vartab, char* value);
	
	private:
	VarS vars;
	VarTab vartab;
	long valuei;
	char valuec;
	long* valuetabi;
	char* valuetabc;
	int index;
	Type type;
		
};

#endif
