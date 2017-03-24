#ifndef VARTAB_H
#define VARTAB_H

#include "Variable.h"
#include <string>

class VarTab : public Variable
{
	public:
	VarTab();
	VarTab(std::string n, long val[]);
	VarTab(std::string n, char val[]);
	
	private:
	std::string nom;
	long[] valuesint;
	char[] valueschar;
		
};

#endif
