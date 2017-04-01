#include "OPBinaire.h"
#include <iostream>

using namespace std;

OPBinaire::OPBinaire()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de OPBinaire" << endl;
	#endif
	typeContenu = _OPBINAIRE;
}

OPBinaire::OPBinaire(Expression* ex1, Expression* ex2, Opbinaire ope)
{
	#ifdef MAP
		cout << "Appel au constructeur de OPBinaire(Expression* ex1, Expression* ex2, Opbinaire ope)" << endl;
	#endif
	e1 = ex1;
	e2 = ex2;
	op = ope;
	typeContenu = _OPBINAIRE;
}

vector<Variable*> OPBinaire::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de opBinaire" << endl;
	#endif
	vector<Variable*> result;
	vector<Variable*> vector1=e1->variableUtilise();
	vector<Variable*> vector2=e2->variableUtilise();
	result.insert( result.end(), vector1.begin(), vector1.end() );
	result.insert( result.end(), vector2.begin(), vector2.end() );
	return result;
}
