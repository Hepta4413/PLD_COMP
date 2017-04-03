#include "BlocWhile.h"
#include "Bloc.h"
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
