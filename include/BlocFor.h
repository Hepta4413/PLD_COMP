#ifndef BLOCFOR_H
#define BLOCFOR_H

#include "BlocControle.h"
#include "Expression.h"

class BlocFor : public BlocControle
{
	public:
	BlocFor();
	BlocFor(Expression c, Expression ini, Expression inc);
	
	private:
	Expression condition;
	Expression incre;
	Expression init;
		
};

#endif
