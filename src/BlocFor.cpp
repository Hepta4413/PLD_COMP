#include "BlocFor.h"
#include "Bloc.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include "../irs/include/BasicBlock.h"
#include <iostream>
#include <sstream>

using namespace std;

BlocFor::BlocFor()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de BlocFor" << endl;
	#endif
	typeContenu = _BLOCFOR;
}

BlocFor::BlocFor(Expression* c, Expression* ini, Expression* inc, Bloc* bloc)
{
	#ifdef MAP
		cout << "Appel au constructeur de BlocFor(Expression* c, Expression* ini, Expression* inc, Bloc* bloc)" << endl;
	#endif
	condition = c;
	init = ini;
	incre = inc;
    boucle=bloc;
	typeContenu = _BLOCFOR;
}

Bloc* BlocFor::getBlocBoucle()
{
	#ifdef MAP
		cout << "Appel a la fonction getBlocBoucle de BlocFor" << endl;
	#endif
	return boucle;
}

Expression* BlocFor::getInit()
{
	#ifdef MAP
		cout << "Appel a la fonction getInit de BlocFor" << endl;
	#endif
	return init;
}

Expression* BlocFor::getIncre()
{
	#ifdef MAP
		cout << "Appel a la fonction getIncre de BlocFor" << endl;
	#endif
	return incre;
}

Expression* BlocFor::getCondition()
{
	#ifdef MAP
		cout << "Appel a la fonction getCondition de BlocFor" << endl;
	#endif
	return condition;
}

void BlocFor::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de Contenu" << endl;
	#endif
    blocParent = blc;
    boucle->setBlocParent(blc);
    boucle->setFonction(blc->getFonction());
    init->setBloc(blc);
    incre->setBloc(blc);
    condition->setBloc(blc);
}

void BlocFor::AddLigneColonne(int ligne,int colonne)
{
	#ifdef MAP
		cout << "Appel a la fonction AddLigneColonne de BlocFor" << endl;
	#endif
	condition->AddLigneColonne( ligne, colonne);
	init->AddLigneColonne( ligne, colonne);
	incre->AddLigneColonne( ligne, colonne);
}

string BlocFor::buildIR(CFG * cfg) {
	#ifdef MAP
		cout << "Appel a la fonction buildIR de BlocIf" << endl;
	#endif
	
	stringstream ss;
	ss << this;

	cfg->createNewBasicBlock();
	init->buildIR(cfg);
	
	vector<string> regs;
	string reg = cfg->create_new_tempvar(CONSTVAL_T);
	regs.push_back("0");
	regs.push_back(reg);
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);
	
	regs.clear();
	regs.push_back("labeldebutfor" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, INT32_T, regs);
	
	regs.clear();
	string reg2 = condition->buildIR(cfg);
	regs.push_back(reg2);
	regs.push_back(reg);
	regs.push_back("labelfinfor" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_NEQ, INT32_T, regs);

	boucle->buildIR(cfg);

	incre->buildIR(cfg);
	regs.clear();
	regs.push_back("labeldebutfor" + ss.str());
	regs.push_back("labelfinfor" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDWHILEFOR, INT32_T, regs);

	return "";
}
