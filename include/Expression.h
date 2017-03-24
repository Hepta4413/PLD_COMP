#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Enums.h"

class Expression : public Ligne
{
	private :
	Expression();
	Expression(Type t, long v);
		
	public :
	Type type;
	long valeur;
	
};

#endif
