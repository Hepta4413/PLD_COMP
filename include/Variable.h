#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include "Enums.h"
#include <string>

using namespace std;

class Variable : public Expression
{
	public:
	Variable();
	void VerifDeclaration(string* nom);
	string* getNom();
	vector<Variable*> variableUtilise();
	bool getLvalue();
	void setLvalue(bool lval);
	
	protected:
	Type type;
	string* nom;
	bool lvalue;
			
};

#endif
