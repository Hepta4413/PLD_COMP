#ifndef VARS_H
#define VARS_H

#include "Variable.h"
#include <string>

class VarS : public Variable
{
	public:
	VarS();
	VarS(std::string n, long val, Type t);
	VarS(long val);
	VarS(std::string n);
	
	private:
	long valueint;
		
};

#endif
