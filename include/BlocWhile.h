#ifndef BLOCWHILE_H
#define BLOCWHILE_H

#include "BlocControle.h"
#include "Expression.h"

class BlocWhile : public BlocControle
{
	public:
	BlocWhile();
	BlocWhile(Expression e);
	
	private:
	Expression condition;	
		
};

#endif
