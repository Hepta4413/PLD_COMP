#ifndef VARTAB_H
#define VARTAB_H

#include "Variable.h"
#include <string>

class VarTab : public Variable
{
	public:
	VarTab();
	VarTab(std::string n, int t, Type typ);
	VarTab(int t);
	
	private:
	long[] valuesint;
	int taille;
};

#endif
