#include "Const.h"
#include <iostream>

using namespace std;

Const::Const()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Const" << endl;
	#endif
}

Const::Const(long value)
{
	#ifdef MAP
		cout << "Appel au constructeur de Const(long value)" << endl;
	#endif
	this->value=value;
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

