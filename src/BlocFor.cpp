#include "BlocFor.h"
#include "Bloc.h"
#include <iostream>

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
    init->setBloc(blc);
    incre->setBloc(blc);
}
