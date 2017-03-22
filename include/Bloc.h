#ifndef BLOC_H
#define BLOC_H

#include "Contenu.h"
#include "Fonction.h"
#include "Variable.h"

class Bloc
{
	public:
	Bloc();
	Bloc(Contenu c, Fonction f,Variable[] var, Bloc bControleParent);
	
	private:
	Contenu cont;
	Fonction fonct;
	Variable[] varbloc;
	Bloc blocControleParent;
		
};

#endif
