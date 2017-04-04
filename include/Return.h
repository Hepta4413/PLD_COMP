#ifndef RETURN_H
#define RETURN_H

#include "Ligne.h"
#include "Expression.h"

class Return : public Ligne
{
	public:
	Return();
	Return(Expression* e);
	Expression* getExpression();
	
	protected:
	Expression* toReturn;
		
};

#endif
