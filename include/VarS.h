#ifndef VARS_H
#define VARS_H

#include "Variable.h"
#include <string>
#include "Enums.h"

class VarS : public Variable
{
	public:
	VarS();
	VarS(std::string* n, long val);
	VarS(Expression* val);
	VarS(std::string* n);

	protected:
	std::string* nom;
	long valueint;

};

#endif
