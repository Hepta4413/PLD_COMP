#ifndef VARTAB_H
#define VARTAB_H

#include "Variable.h"
#include <string>

class VarTab : public Variable
{
	public:
	VarTab();
	VarTab(std::string* n, Expression* t, bool taille);
	VarTab(int t, bool taille);

	private:
	long valuesint[];
	int valeur;
	bool taille;
};

#endif
