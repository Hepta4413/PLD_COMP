#ifndef VARS_H
#define VARS_H

#include "Variable.h"
#include <string>

class VarS : public Variable
{
	public:
	VarS();
	VarS(std::string n, long val);
	VarS(std::string n, char val);
	
	private:
	std::string nom;
	long valueint;
	char valuechar;
		
};

#endif
