#ifndef BLOCCONTROLE_H
#define BLOCCONTROLE_H

#include "Contenu.h"
#include "Bloc.h"

class BlocControle : public Contenu
{
	public:
	BlocControle();
	BlocControle(Bloc bparent, Bloc bfils);
	
	private:
	Bloc blocParent;
	Bloc blocFils;
		
};

#endif
