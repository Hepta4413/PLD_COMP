#ifndef BLOCFOR_H
#define BLOCFOR_H

#include "BlocControle.h"
#include "Expression.h"
#include "Enums.h"

class BlocFor : public BlocControle
{
	public:
	BlocFor();
	BlocFor(Expression* c, Expression* ini, Expression* inc, Bloc* bloc);
	Bloc* getBlocBoucle();
	Expression* getCondition();
	Expression* getInit();
	Expression* getIncre();
	void setBloc(Bloc* blc);
	void AddLigneColonne(int ligne,int colonne);
	
	private:
	Expression* condition;
	Expression* incre;
	Expression* init;
	Bloc* boucle;
		
};

#endif
