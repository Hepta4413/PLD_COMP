#ifndef BLOCIF_H
#define BLOCIF_H

#include "BlocControle.h"
#include "Expression.h"
#include "Enums.h"

class CFG;
class IRInstr;
class BasicBlock;

class BlocIf : public BlocControle
{
	public:
	BlocIf();
	BlocIf(Bloc* bloc);
	void AddIf(Expression* expr, Bloc* bloc);
	Bloc* getBlocAlors();
	Bloc* getBlocSinon();
	bool elsePresent();
	Expression* getCondition();
	void setBloc(Bloc* blc);
	void AddLigneColonne(int ligne,int colonne);
	bool getContientRetour();
	string buildIR(CFG * cfg);

	private:
	Expression* si;
	Bloc* sinon;
	Bloc* alors;

};

#endif
