#include "BlocIf.h"
#include <iostream>

using namespace std;

BlocIf::BlocIf()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de BlocIf" << endl;
	#endif
}

BlocIf::BlocIf(Bloc* bloc)
{
	#ifdef MAP
		cout << "Appel au constructeur de BlocIf(Bloc* bloc)" << endl;
	#endif
    sinon = bloc;
}

void BlocIf::AddIf(Expression* expr, Bloc* bloc)
{
	#ifdef MAP
		cout << "Appel au constructeur de BlocIf(Expression* expr, Bloc* bloc)" << endl;
	#endif
    si = expr;
    alors = bloc;
}
