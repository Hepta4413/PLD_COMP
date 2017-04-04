#ifndef OPBINAIRE_H
#define OPBINAIRE_H

#include "Enums.h"
#include "Expression.h"

class OPBinaire : public Expression
{
	public :
	OPBinaire();
	OPBinaire(Expression* e1, Expression* e2, Opbinaire op);
	vector<Variable*> variableUtilise();
	Type calculType ();
	void setBloc(Bloc* blc);
	
	protected :
	Expression* e1;
	Expression* e2;
	Opbinaire op;

};

#endif
