#ifndef CONST_H
#define CONST_H

#include "Expression.h"
#include "Enums.h"
#include <string>

class Const : public Expression
{
	public:
	Const();
	Const(long value);
	
	protected:
	long value;
		
};

#endif
