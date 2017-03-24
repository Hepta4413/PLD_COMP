#ifndef CONTENU_H
#define CONTENU_H

//#include "Bloc.h"

class Bloc;

class Contenu
{
	public:
	Contenu();
	Contenu(Bloc * b);
	
	private:
	Bloc * blocParent;
		
};

#endif
