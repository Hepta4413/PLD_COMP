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
	VarTab(string* n, Const* t, bool taille);
	VarTab(long t, bool taille);

	private:
	long valeur;
	bool taille;
};

#endif
