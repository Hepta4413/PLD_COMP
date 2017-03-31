#ifndef BLOCCONTROLE_H
#define BLOCCONTROLE_H

#include "Contenu.h"

class BlocControle : public Contenu
{
	public:
	BlocControle();
	BlocControle(Bloc * bfils);
	int getSize();
	
	private:
	Bloc * blocFils;
		
};

#endif
