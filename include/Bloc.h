#ifndef BLOC_H
#define BLOC_H

#include "Contenu.h"
#include "Fonction.h"
#include "Variable.h"
#include <Vector>

class Contenu;
class Variable;

class Bloc
{
	public:
	Bloc();
	Bloc(Contenu c, Fonction f,Variable var[], Bloc bControleParent);
	AddContenu(Contenu c);
	
	private:
	Vector<Contenu> cont;
	Fonction fonct;
	Variable[] varbloc;
	Bloc blocControleParent;
		
};

#endif
