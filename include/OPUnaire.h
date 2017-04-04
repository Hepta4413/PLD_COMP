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
	string buildIR(CFG * cfg);

	protected :
	Expression* exp;
	Opunaire op;

};

#endif
