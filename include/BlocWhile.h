#ifndef BLOCWHILE_H
#define BLOCWHILE_H

#include "BlocControle.h"

using namespace std;

class BlocWhile : public BlocControle
{
	public:
	BlocControle(Expression e);
	
	private:
	Expression condition;
	
	
		
};

#endif
