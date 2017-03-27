#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Enums.h"
#include "Ligne.h"

class Expression : public Ligne
{
	public :
	Expression();
	Expression(Type t, long v);
		
	protected :
	Type type;
	long valeur;
	
};

#endif
