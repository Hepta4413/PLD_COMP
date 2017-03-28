#ifndef VARTAB_H
#define VARTAB_H

#include "Variable.h"
#include "Const.h"
#include <string>

using namespace std;

class VarTab : public Variable
{
	public:
	VarTab();
	VarTab(string* n, Expression* t, bool taille);
	VarTab(Expression* t, bool taille);

	private:
	Expression* valeur;
	bool taille;
};

#endif
