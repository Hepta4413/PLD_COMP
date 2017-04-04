#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "VarTab.h"
#include "VarS.h"
#include "Expression.h"
#include "Enums.h"

class Affectation : public Expression
{
	public:
	Affectation();
	Affectation(Variable* vars, Expression* value, Opbinaire op);
	Affectation(VarTab* vartab, Expression* value, int i, Opbinaire op);
	vector<Variable*> variableUtilise();
	Type calculType ();
	string buildIR(CFG * cfg);
	void setBloc(Bloc* blc);

	protected:
	Variable* vars;
	Expression* valuei;
	int index;
	Opbinaire operateur;

};

#endif
