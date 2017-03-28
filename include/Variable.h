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
	Variable(Type t, string* n);
	void AddInfo(Type t, string* n);
	
	protected:
	Type type;
	string* nom;
	bool declaration;
			
};

#endif
