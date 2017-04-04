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
	bool getRvalue();
	void setRvalue(bool lval);
	Type calculType ();
	void setType(Type t);
	void setBloc(Bloc* blc);
	
	protected:
	string* nom;
	bool lvalue;
	bool rvalue;
			
};

#endif
