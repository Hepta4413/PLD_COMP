#ifndef CONTENU_H
#define CONTENU_H

#include "Enums.h"
#include <string>

class Bloc;
class CFG;
class Declaration;

using namespace std;

class Contenu
{
	public:
	Contenu();
	Contenu(Bloc* b);

	Bloc* getBloc();
	virtual void setBloc(Bloc* blc);
	TypeContenu getTypeContenu();
	virtual int getSize() =0;
	virtual string buildIR(CFG * cfg) = 0;

	protected:
	Bloc* blocParent;
	TypeContenu typeContenu;


};

#endif
