#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include "Enums.h"

class Variable : public Expression
{
	public:
	Variable();
	Variable(Type t);
	
	private:
	Type type;
		
};

#endif
