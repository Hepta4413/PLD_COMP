#ifndef BLOCCONTROLE_H
#define BLOCCONTROLE_H

#include "Contenu.h"
#include "Enums.h"

using namespace std;

class BlocControle : public Contenu
{
	public:
	BlocControle();
	
	private:
	Expression condition;
	
		
};

#endif
