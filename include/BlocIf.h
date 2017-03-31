#ifndef BLOCIF_H
#define BLOCIF_H

#include "BlocControle.h"
#include "Expression.h"
#include "Enums.h"

class BlocIf : public BlocControle
{
	public:
	BlocIf();
	BlocIf(Bloc* bloc);
	void AddIf(Expression* expr, Bloc* bloc);
	
	private:
	Expression* si;	
	Bloc* sinon;
	Bloc* alors;
		
};

#endif
