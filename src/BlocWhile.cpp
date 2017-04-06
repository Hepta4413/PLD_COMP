#include "BlocWhile.h"
#include "Bloc.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include "../irs/include/BasicBlock.h"
#include <iostream>
#include <sstream>


using namespace std;

BlocWhile::BlocWhile()
{
		#ifdef MAP
		cout << "Appel au constructeur vide de BlocWhile" << endl;
	#endif
	typeContenu = _BLOCWHILE;
}

BlocWhile::BlocWhile(Expression* e, Bloc* bloc)
{
	#ifdef MAP
		cout << "Appel au constructeur de BlocWhile(Expression* expr, Bloc* bloc)" << endl;
	#endif
	condition = e;
    boucle=bloc;
	typeContenu = _BLOCWHILE;
}

Bloc* BlocWhile::getBlocBoucle()
{
	#ifdef MAP
		cout << "Appel a la fonction getBlocBoucle de BlocWhile" << endl;
	#endif
	return boucle;
}

Expression* BlocWhile::getCondition()
{
	#ifdef MAP
		cout << "Appel a la fonction getCondition de BlocWhile" << endl;
	#endif
	return condition;
}

void BlocWhile::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de BlocIf" << endl;
	#endif
    blocParent = blc;
    boucle->setBlocParent(blc);
    boucle->setFonction(blc->getFonction());
	condition->setBloc(blc);
}

void BlocWhile::AddLigneColonne(int ligne,int colonne)
{
	#ifdef MAP
		cout << "Appel a la fonction AddLigneColonne de BlocWhile" << endl;
	#endif
	condition->AddLigneColonne( ligne, colonne);
}

string BlocWhile::buildIR(CFG * cfg) {
		#ifdef MAP
		cout << "Appel a la fonction buildIR de BlocIf" << endl;
	#endif
	
	stringstream ss;
	ss << this;

	cfg->createNewBasicBlock();
	
	vector<string> regs;
	string reg = cfg->create_new_tempvar(CONSTVAL_T);
	regs.push_back("0");
	regs.push_back(reg);
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, CONSTVAL_T, regs);
	
	regs.clear();
	regs.push_back("labeldebutwhile" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LABEL, INT32_T, regs);
	
	regs.clear();
	string reg2 = condition->buildIR(cfg);
	regs.push_back(reg2);
	regs.push_back(reg);
	regs.push_back("labelfinwhile" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_NEQ, INT32_T, regs);

	boucle->buildIR(cfg);

	regs.clear();
	regs.push_back("labeldebutwhile" + ss.str());
	regs.push_back("labelfinwhile" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDWHILEFOR, INT32_T, regs);

	return "";
}
