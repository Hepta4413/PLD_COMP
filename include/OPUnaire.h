#ifndef OPUNAIRE_H
#define OPUNAIRE_H

#include "Enums.h"
#include "Expression.h"

class OPUnaire : public Expression
{
	public :
	OPUnaire();
	OPUnaire(Expression* e, Opunaire op);
	vector<Variable*> variableUtilise();
	Type calculType ();
	void setBloc(Bloc* blc);

	protected :
	Expression* exp;
	Opunaire op;

};

#endif
