#ifndef CONTENU_H
#define CONTENU_H

#include "Bloc.h"
#include "Enums.h"

class Bloc;
//class Bloc;
class Declaration;

class Contenu
{
	public:
	Contenu();
	Contenu(Bloc* b);

	Bloc* getBloc();
	virtual void setBloc(Bloc* blc);
	TypeContenu getTypeContenu();
	virtual int getSize() =0;
	
	protected:
	Bloc* blocParent;
	TypeContenu typeContenu;


};

#endif
