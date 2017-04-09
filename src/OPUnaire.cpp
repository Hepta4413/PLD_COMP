#include "OPUnaire.h"
#include "../irs/include/IRInstr.h"
#include "../irs/include/CFG.h"
#include "Const.h"
#include <iostream>
#include <sstream>

using namespace std;

OPUnaire::OPUnaire()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de OPUnaire" << endl;
	#endif
	typeContenu = _OPUNAIRE;
}

OPUnaire::OPUnaire(Expression* e, Opunaire ope)
{
	#ifdef MAP
		cout << "Appel au constructeur de OPUnaire(Expression* e, Opunaire ope)" << endl;
	#endif
	exp = e;
	op = ope;
	typeContenu = _OPUNAIRE;
}

vector<Variable*> OPUnaire::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de opUnaire" << endl;
	#endif
	return exp->variableUtilise();
}

Type OPUnaire::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction calculType de OPUnaire" << endl;
	#endif
	type=exp->calculType();
	return type;
}

string OPUnaire::buildIR(CFG * cfg) {
	Const one(1);
	string reg1 = exp->buildIR(cfg);
	string reg2 = one.buildIR(cfg);
	string regtemp = cfg->create_new_tempvar(calculType());


	vector<string> regs;
	vector<string> regs2;
	regs2.push_back(reg1);
	regs2.push_back(regtemp);
	
	
	switch (op) {
		case INCR_OU_FRONT :
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back(reg1);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ADD, calculType(), regs);
			return reg1;
		break;
		case INCR_OU_BACK :
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back(reg1);		
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::WMEM, calculType(), regs2);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ADD, calculType(), regs);
			return regtemp;
		break;
		case DECR_OU_FRONT :		
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back(reg1);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::SUB, calculType(), regs);
			return reg1;
		break;
		case DECR_OU_BACK :
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back(reg1);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::WMEM, calculType(), regs2);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::SUB, calculType(), regs);
			return regtemp;
		break;
		case NOT_OU :
			
		break;
		default:
		break;
		
	}
	return "";
}

void OPUnaire::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de OPUnaire" << endl;
	#endif
    blocParent = blc;
	exp->setBloc(blc);
}
