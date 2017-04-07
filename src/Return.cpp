#include "Return.h"
#include "IRInstr.h"
#include "CFG.h"
#include <iostream>


using namespace std;

Return::Return()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Return" << endl;
	#endif
	typeContenu = _RETURN;
}

Return::Return(Expression* e)
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Return(Expression* e)" << endl;
	#endif
	toReturn = e;
	typeContenu = _RETURN;
}

Expression* Return::getExpression()
{
	#ifdef MAP
		cout << "Appel a la fonction getExpression de Return" << endl;
	#endif
	return toReturn;
}

string Return::buildIR(CFG * cfg) {
	string reg1 = toReturn->buildIR(cfg);
	vector<string> regs;
	regs.push_back(reg1);
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::RETURN, INT64_T, regs);
	return "ok";
}
