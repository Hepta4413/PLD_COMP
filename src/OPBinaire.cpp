#include "OPBinaire.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include <iostream>
#include <sstream>

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
	string reg1;
	string reg2;
	string reg3;
	string reg0;

	vector<string> regs;

	stringstream ss;
	ss << this;

	switch (op) {
		case PLUS_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);

			regs.push_back(reg3);
			regs.push_back(reg2);
			regs.push_back(reg1);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ADD, calculType(), regs);
		break;
		case MINUS_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);

			regs.push_back(reg3);
			regs.push_back(reg2);
			regs.push_back(reg1);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::SUB, calculType(), regs);
		break;
		case MULT_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);

			regs.push_back(reg3);
			regs.push_back(reg2);
			regs.push_back(reg1);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		/*
		case DIV_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;*/
		case UPPERTHAN_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);

			regs.clear();
			regs.push_back(reg2);
			regs.push_back(reg1);
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_LE, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		case UPPEROREQUAL_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);
		
			regs.clear();
			regs.push_back(reg2);
			regs.push_back(reg1);
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_LT, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		case LOWERTHAN_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);
			
			regs.clear();
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_LT, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		
		case LOWEROREQUAL_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);
			
			regs.clear();
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_LE, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		
		case DOUBLEEQUAL_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);
			
			regs.clear();
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_EQ, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		/*
		case MODULO_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		 */
		case NOTEQUAL_OB:
			reg1 = e1->buildIR(cfg);
			reg2 = e2->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);
			
			regs.clear();
			regs.push_back(reg1);
			regs.push_back(reg2);
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_NEQ, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			regs.push_back("labelsinon" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		case OR_OB:
			reg1 = e1->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);
			reg0 = cfg->create_new_tempvar(type);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg0);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back(reg1);
			regs.push_back(reg0);
			regs.push_back("labelsinon1" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_NEQ, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors1" + ss.str());
			regs.push_back("labelsinon1" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			reg2 = e2->buildIR(cfg);
			
			regs.clear();
			regs.push_back(reg2);
			regs.push_back(reg0);
			regs.push_back("labelsinon2" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_NEQ, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors2" + ss.str());
			regs.push_back("labelsinon2" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);
			
			regs.clear();
			regs.push_back("labelalors2" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
			
			regs.clear();
			regs.push_back("labelalors1" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		case AND_OB:
			reg1 = e1->buildIR(cfg);
			reg3 = cfg->create_new_tempvar(type);
			reg0 = cfg->create_new_tempvar(type);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg0);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back(reg1);
			regs.push_back(reg0);
			regs.push_back("labelsinon1" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_EQ, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors1" + ss.str());
			regs.push_back("labelsinon1" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			reg2 = e2->buildIR(cfg);
			
			regs.clear();
			regs.push_back(reg2);
			regs.push_back(reg0);
			regs.push_back("labelsinon2" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_EQ, type, regs);

			regs.clear();
			regs.push_back("0");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);

			regs.clear();
			regs.push_back("labelalors2" + ss.str());
			regs.push_back("labelsinon2" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, type, regs);

			regs.clear();
			regs.push_back("1");
			regs.push_back(reg3);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);
			
			regs.clear();
			regs.push_back("labelalors2" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
			
			regs.clear();
			regs.push_back("labelalors1" + ss.str());
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, type, regs);
		break;
		
		default:
		break;
	}

	return reg3;

}
