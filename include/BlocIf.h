#ifndef BLOCIF_H
#define BLOCIF_H

#include "BlocControle.h"
#include "Expression.h"

class BlocIf : public BlocControle
{
	public:
	BlocIf();
	BlocIf(Expression e);
	
	private:
	Expression condition;	
		
};

#endif
