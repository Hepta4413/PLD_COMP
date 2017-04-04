#include "BlocIf.h"
#include "Bloc.h"
#include <iostream>

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
		cout << "Appel a la fonction elsePresent de BlocIf" << endl;
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
	return "";
}
