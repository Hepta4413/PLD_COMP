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
		cout << "Appel a la fonction calculType de Const" << endl;
	#endif
	type = CONSTVAL_T;
	return CONSTVAL_T;
}

string Const::buildIR(CFG * cfg) {
	#ifdef MAP
		cout << "Appel a la fonction buildIR de Const" << endl;
	#endif
	string reg = cfg->create_new_tempvar(type);
	vector<string> regs;
	regs.push_back(to_string(value));
	regs.push_back(reg);
	cout<<value<<" CECI EST LA VALEUR DU REGS[0] "<<regs.size()<<" "<<regs.at(0)<<endl;
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, type, regs);
	return reg;

}
