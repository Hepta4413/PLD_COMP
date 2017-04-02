#ifndef CONST_H
#define CONST_H

#include "Expression.h"
#include "Enums.h"
#include <string>

class Const : public Expression
{
	public:
	Const();
	Const(long value);
	long getValue();
	vector<Variable*> variableUtilise();
	Type calculType ();

	protected:
	long value;

};

#endif
