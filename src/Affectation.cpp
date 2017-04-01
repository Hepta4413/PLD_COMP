#include "Affectation.h"
#include "Variable.h"
#include <vector>
#include <iostream>

using namespace std;

Affectation::Affectation()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Affectation" << endl;
	#endif
	typeContenu = _AFFECTATION;
}

Affectation::Affectation(Variable* var, Expression* value, Opbinaire op)
{
	#ifdef MAP
		cout << "Appel au constructeur de Affectation(Variable* var, Expression* value, Opbinaire op)" << endl;
	#endif
	vars = var;
	valuei = value;
  operateur=op;
	typeContenu = _AFFECTATION;
}

vector<Variable*> Affectation::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de Affectation" << endl;
	#endif
	vector<Variable*> result;
	result.push_back(vars);
	vector<Variable*> resultIntermediaire = valuei->variableUtilise();
	result.insert( result.end(), resultIntermediaire.begin(), resultIntermediaire.end() );
	return result;
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
	typeContenu = _AFFECTATION;
}
