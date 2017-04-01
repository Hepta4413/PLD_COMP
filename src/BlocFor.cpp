#include "BlocFor.h"
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
