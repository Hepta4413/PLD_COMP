#include "BlocControle.h"
#include <iostream>

using namespace std;

BlocControle::BlocControle()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de BlocControle" << endl;
	#endif
}

BlocControle::BlocControle(Bloc * bfils)
{
	#ifdef MAP
		cout << "Appel au constructeur de BlocControle(Bloc * bfils)" << endl;
	#endif
	blocFils = bfils;
}

Bloc* BlocControle::getBlocFils()
{
	#ifdef MAP
		cout << "Appel a la fonction get blocFils BlocControle(Bloc * bfils)" << endl;
	#endif
	return blocFils;
}
