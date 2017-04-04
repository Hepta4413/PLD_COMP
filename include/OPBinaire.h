#ifndef OPBINAIRE_H
#define OPBINAIRE_H

#include "Enums.h"
#include "Expression.h"

class CFG;
class IRInstr;

class OPBinaire : public Expression
{
	public :
	OPBinaire();
	OPBinaire(Expression* e1, Expression* e2, Opbinaire op);
	vector<Variable*> variableUtilise();
	Type calculType ();
	string buildIR(CFG * cfg);

	protected :
	Expression* e1;
	Expression* e2;
	Opbinaire op;

};

#endif
