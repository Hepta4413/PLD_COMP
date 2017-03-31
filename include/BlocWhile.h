#ifndef BLOCWHILE_H
#define BLOCWHILE_H

#include "BlocControle.h"
#include "Expression.h"
#include "Enums.h"

class BlocWhile : public BlocControle
{
	public:
	BlocWhile();
	BlocWhile(Expression* e, Bloc* bloc);
	
	protected:
	Expression* condition;	
	Bloc* boucle;
};

#endif
