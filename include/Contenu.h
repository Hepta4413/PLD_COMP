#ifndef CONTENU_H
#define CONTENU_H

//#include "Bloc.h"

class Bloc;
class Declaration;

class Contenu
{
	public:
	Contenu();
	Contenu(Bloc * b);
	
	protected:
	Bloc * blocParent;
		
};

#endif
