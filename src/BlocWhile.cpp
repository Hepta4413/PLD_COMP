#include "BlocWhile.h"
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
