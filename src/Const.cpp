#include "Const.h"
#include <iostream>

using namespace std;

Const::Const()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Const" << endl;
	#endif
	type = CONSTVAL_T;
	typeContenu = _CONST;
}

Const::Const(long value)
{
	#ifdef MAP
		cout << "Appel au constructeur de Const(long value)" << endl;
	#endif
	this->value=value;
	type = CONSTVAL_T;
	typeContenu = _CONST;
}

vector<Variable*> Const::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de Const" << endl;
	#endif
	vector<Variable*> result;
	return result;
}

long Const::getValue()
{
	#ifdef MAP
		cout << "Appel a la fonction getValue de Const" << endl;
	#endif
	return value;
}

Type Const::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction AppelFonct de Const" << endl;
	#endif
	type = CONSTVAL_T;
	return CONSTVAL_T;
}

