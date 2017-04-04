#ifndef BLOCCONTROLE_H
#define BLOCCONTROLE_H

#include "Contenu.h"
#include "Enums.h"
//#include "Bloc.h"

class Bloc;
class CFG;

class BlocControle : public Contenu
{
	public:
	BlocControle();
	BlocControle(Bloc * bfils);
	Bloc* getBlocFils();
	virtual void setBloc(Bloc* blc);
	virtual void AddLigneColonne(int ligne,int colonne)=0;
	int getSize();
	string buildIR(CFG * cfg);

	private:
	Bloc * blocFils;

};

#endif
