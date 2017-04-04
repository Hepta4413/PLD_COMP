#include "BlocWhile.h"
#include "Bloc.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include "../irs/include/BasicBlock.h"
#include <iostream>

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
	BasicBlock* beforeWhileBB = cfg->current_bb;
	BasicBlock* bodyBB = new BasicBlock(cfg);
	BasicBlock* testBB = new BasicBlock(cfg);

	cfg->current_bb = testBB;
	condition->buildIR(cfg);

	/* TODO add
	bodyBB = new BasicBlock(cfg, boucle);
	*/
	BasicBlock* afterWhileBB = new BasicBlock(cfg);
	afterWhileBB->exit_true = beforeWhileBB->exit_true;
	afterWhileBB->exit_false = beforeWhileBB->exit_false;
	testBB->exit_true = bodyBB;
	testBB->exit_false = afterWhileBB;
	bodyBB->exit_true = testBB;
	bodyBB->exit_false = NULL;
	cfg->current_bb = afterWhileBB;
	return "";
}
