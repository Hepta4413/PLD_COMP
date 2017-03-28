#ifndef VARS_H
#define VARS_H

#include "Variable.h"
#include <string>
#include "Enums.h"

using namespace std;

class VarS : public Variable
{
	public:
	VarS();
	VarS(long val);
	VarS(string* n, long val);
	VarS(Expression* val);
	VarS(string* n);

	protected:
	string* nom;
	long valueint;

};

#endif
