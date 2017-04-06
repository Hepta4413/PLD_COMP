#include "BlocIf.h"
#include "Bloc.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include "../irs/include/BasicBlock.h"
#include <iostream>
#include <sstream>

using namespace std;

BlocIf::BlocIf()
{
	#ifdef MAP
	cout << "Appel au constructeur vide de BlocIf" << endl;
	#endif
	sinon=NULL;
	typeContenu = _BLOCIF;
}

BlocIf::BlocIf(Bloc* bloc)
{
	#ifdef MAP
	cout << "Appel au constructeur de BlocIf(Bloc* bloc)" << endl;
	#endif
	sinon = bloc;
	typeContenu = _BLOCIF;
}

void BlocIf::AddIf(Expression* expr, Bloc* bloc)
{
	#ifdef MAP
	cout << "Appel au constructeur de BlocIf(Expression* expr, Bloc* bloc)" << endl;
	#endif
	si = expr;
	alors = bloc;
}

Bloc* BlocIf::getBlocAlors()
{
	#ifdef MAP
	cout << "Appel a la fonction getBlocAlors de BlocIf" << endl;
	#endif
	return alors;
}

Bloc* BlocIf::getBlocSinon()
{
	#ifdef MAP
	cout << "Appel a la fonction getBlocSinon de BlocIf" << endl;
	#endif
	return sinon;
}

bool BlocIf::elsePresent()
{
	#ifdef MAP
	cout << "Appel a la fonction elsePresent de BlocIf" <<sinon<< endl;
	#endif
	return sinon!=NULL;
}

Expression* BlocIf::getCondition()
{
	#ifdef MAP
	cout << "Appel a la fonction getCondition de BlocIf" << endl;
	#endif
	return si;
}

void BlocIf::setBloc(Bloc* blc)
{
	#ifdef MAP
	cout << "Appel a la fonction setBloc de BlocIf" << endl;
	#endif
	blocParent = blc;
	alors->setBlocParent(blc);
	alors->setFonction(blc->getFonction());
	si->setBloc(blc);
	if(elsePresent())
	{
		sinon->setBlocParent(blc);
		sinon->setFonction(blc->getFonction());
	}
}

void BlocIf::AddLigneColonne(int ligne,int colonne)
{
	#ifdef MAP
	cout << "Appel a la fonction AddLigneColonne de BlocIf" << endl;
	#endif
	si->AddLigneColonne( ligne, colonne);
}

bool BlocIf::getContientRetour()
{
	#ifdef MAP
	cout << "Appel a la fonction getContientRetour de BlocIf" << endl;
	#endif
	return (alors->getContientRetour() && elsePresent() && sinon->getContientRetour());
}

string BlocIf::buildIR(CFG * cfg) {
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
	string reg2 = si->buildIR(cfg);
	regs.push_back(reg2);
	regs.push_back(reg);
	regs.push_back("labelsinon" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::CMP_NEQ, INT32_T, regs);

	cout<<"end if"<<endl;
	alors->buildIR(cfg);
	regs.clear();
	regs.push_back("labelalors" + ss.str());
	regs.push_back("labelsinon" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDIF, INT32_T, regs);

	cout<<"end ELSE"<<endl;
	if(elsePresent())
	{
		sinon->buildIR(cfg);
	}
	regs.clear();
	regs.push_back("labelalors" + ss.str());
	cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ENDELSE, INT32_T, regs);

	return "";
}
