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
	void AddInfo(Type t);
	
	protected:
	Type type;
	string* nom;
	bool declaration;
			
};

#endif
