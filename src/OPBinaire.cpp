#include "OPBinaire.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include <iostream>

using namespace std;

OPBinaire::OPBinaire()
{
	#ifdef MAP
	cout << "Appel au constructeur vide de OPBinaire" << endl;
	#endif
	typeContenu = _OPBINAIRE;
}

OPBinaire::OPBinaire(Expression* ex1, Expression* ex2, Opbinaire ope)
{
	#ifdef MAP
	cout << "Appel au constructeur de OPBinaire(Expression* ex1, Expression* ex2, Opbinaire ope)" << endl;
	#endif
	e1 = ex1;
	e2 = ex2;
	op = ope;
	typeContenu = _OPBINAIRE;
}

void OPBinaire::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de OPBinaire" << endl;
	#endif
    blocParent = blc;
	e1->setBloc(blc);
	e2->setBloc(blc);
}

vector<Variable*> OPBinaire::variableUtilise(){
	#ifdef MAP
	cout << "Appel a la fonction variableUtilise de opBinaire" << endl;
	#endif
	vector<Variable*> result;
	vector<Variable*> vector1=e1->variableUtilise();
	vector<Variable*> vector2=e2->variableUtilise();
	result.insert( result.end(), vector1.begin(), vector1.end() );
	result.insert( result.end(), vector2.begin(), vector2.end() );
	return result;
}

Type OPBinaire::calculType()
{
	#ifdef MAP
	cout << "Appel a la fonction calculType de OPBinaire" << endl;
	#endif
	Type typeE1 = e1->calculType();
	Type typeE2 = e2->calculType();
	if(typeE1==CONSTVAL_T || typeE2==CONSTVAL_T || typeE1==typeE2)
	{
		type=(typeE1==CONSTVAL_T?typeE2:typeE1);
		return type;
	}
	else
	{
		#ifdef WAR
		cerr<<"Warning ligne "<<getLigne()<<" : "
		<<getColonne()<<" opération sur des types différents "<<typeE1<<" "<<typeE2<<endl;
		#endif
		return INT32_T;

	}
}

string OPBinaire::buildIR(CFG * cfg) {
	string reg1 = e1->buildIR(cfg);
	string reg2 = e2->buildIR(cfg);
	string reg3 = cfg->create_new_tempvar(calculType());

	vector<string> regs;
	regs.push_back(reg3);
	regs.push_back(reg2);
	regs.push_back(reg1);

	switch (op) {
		case PLUS_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ADD, calculType(), regs);
		break;
		case MINUS_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::SUB, calculType(), regs);
		break;
		case MULT_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		/*
		case EQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case DIV_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case UPPERTHAN_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case UPPEROREQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case LOWERTHAN_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case LOWEROREQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case PLUSEQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case MINUSEQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case DIVEQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case MULTEQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case DOUBLEEQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case MODULO_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case NOTEQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case OR_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		case AND_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		*/
	}

	return reg1;

}
