#ifndef BLOCCONTROLE_H
#define BLOCCONTROLE_H

#include "Contenu.h"
#include "Enums.h"
//#include "Bloc.h"

class Bloc;

class BlocControle : public Contenu
{
	public:
	BlocControle();
	BlocControle(Bloc * bfils);
	Bloc* getBlocFils();
	
	private:
	Bloc * blocFils;
		
};

#endif
