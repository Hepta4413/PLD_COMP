#ifndef BLOCIF_H
#define BLOCIF_H

#include "BlocControle.h"

using namespace std;

class BlocIf : public BlocControle
{
	public:
	BlocIf(Expression e);
	
	private:
	Expression condition;
	
	
	
		
};

#endif
