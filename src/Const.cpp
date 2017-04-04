#include "Const.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include <iostream>

using namespace std;

Const::Const()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Const" << endl;
	#endif
	type = CONSTVAL_T;
	typeContenu = _CONST;
}

Const::Const(long value)
{
	#ifdef MAP
		cout << "Appel au constructeur de Const(long value)" << endl;
	#endif
	this->value=value;
	type = CONSTVAL_T;
	typeContenu = _CONST;
}

vector<Variable*> Const::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de Const" << endl;
	#endif
	vector<Variable*> result;
	return result;
}

long Const::getValue()
{
	#ifdef MAP
		cout << "Appel a la fonction getValue de Const" << endl;
	#endif
	return value;
}

Type Const::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction AppelFonct de Const" << endl;
	#endif
	type = CONSTVAL_T;
	return CONSTVAL_T;
}

string Const::buildIR(CFG * cfg) {
	string reg = cfg->create_new_tempvar(calculType());
	vector<string> regs;
	regs.push_back(reg);
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, calculType(), regs);
	return reg;

}
