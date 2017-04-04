#ifndef VARS_H
#define VARS_H

#include "Variable.h"
#include <string>
#include "Enums.h"

using namespace std;

class Variable;

class VarS : public Variable
{
	public:
	VarS();
	VarS(string* n);
	string buildIR(CFG * cfg);

	protected:

};

#endif
