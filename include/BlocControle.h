#ifndef BLOCCONTROLE_H
#define BLOCCONTROLE_H

#include "Contenu.h"
#include "Enums.h"

using namespace std;

class BlocControle : public Contenu
{
	public:
	BlocControle(Expression e, TypeControle t);
	
	private:
	Expression condition;
	TypeControle type;
	
	
	
		
};

#endif
