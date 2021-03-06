#ifndef VARTAB_H
#define VARTAB_H

#include "Variable.h"
#include "Const.h"
#include <string>
#include "Enums.h"

using namespace std;

class VarTab : public Variable
{
	public:
	VarTab();
	VarTab(string* n, Expression* t);
	string buildIR(CFG * cfg);

	private:
	Expression* indice;
};

#endif
