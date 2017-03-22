#ifndef VARTAB_H
#define VARTAB_H

#include "Variable.h"
#include <string>

class VarTab : public Variable
{
	public:
	VarTab();
	VarTab(std::string n, int64_t[] val);
	VarTab(std::string n, char[] val);
	
	private:
	std::string nom;
	int64_t[] valuesint;
	char[] valueschar;
		
};

#endif
