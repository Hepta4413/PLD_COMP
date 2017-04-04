#ifndef BLOCWHILE_H
#define BLOCWHILE_H

#include "BlocControle.h"
#include "Expression.h"
#include "Enums.h"

class BlocWhile : public BlocControle
{
	public:
	BlocWhile();
	BlocWhile(Expression* e, Bloc* bloc);
	Bloc* getBlocBoucle();
	Expression* getCondition();
	void setBloc(Bloc* blc);
	void AddLigneColonne(int ligne,int colonne);
	string buildIR(CFG * cfg);

	protected:
	Expression* condition;
	Bloc* boucle;
};

#endif
