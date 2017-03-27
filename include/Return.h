#ifndef RETURN_H
#define RETURN_H

#include "Ligne.h"
#include "Expression.h"

class Return : public Ligne
{
	public:
	Return();
	Return(Expression* e);
	
	protected:
	Expression* toReturn;
		
};

#endif
