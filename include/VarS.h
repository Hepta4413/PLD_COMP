#ifndef VARS_H
#define VARS_H

#include "Variable.h"
#include <string>

class VarS : public Variable
{
	public:
	VarS();
	VarS(std::string n, int64_t val);
	VarS(std::string n, char val);
	
	private:
	std::string nom;
	int64_t valueint;
	char valuechar;
		
};

#endif
