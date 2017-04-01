#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Enums.h"
#include "Ligne.h"
#include <vector>

class Variable;

using namespace std;

class Expression : public Ligne
{
	public :
	Expression();
	Expression(Type t);
	virtual vector<Variable*> variableUtilise() =0; //attention le vector peut être vide

	protected :
	Type type;

};

#endif
