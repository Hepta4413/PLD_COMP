#include "Affectation.h"
#include <iostream>

using namespace std;

Affectation::Affectation()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Affectation" << endl;
	#endif
}

Affectation::Affectation(Variable* var, Expression* value, Opbinaire op)
{
	#ifdef MAP
		cout << "Appel au constructeur de Affectation(Variable* var, Expression* value, Opbinaire op)" << endl;
	#endif
	vars = var;
	valuei = value;
  operateur=op;
}

Affectation::Affectation(VarTab* var, Expression* value, int i, Opbinaire op)
{
	#ifdef MAP
		cout << "Appel au constructeur de Affectation(VarTab* var, Expression* value, int i, Opbinaire op)" << endl;
	#endif
	vartab = var;
	valuei = value;
	index = i;
  operateur=op;
}
