#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Enums.h"

class Expression : public Ligne
{
	private :
	Expression();
	Expression(Type t);
		
	public :
	Type type;
	
};

#endif
