#include "BlocControle.h"
#include "../irs/include/CFG.h"
#include <iostream>

using namespace std;

BlocControle::BlocControle()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de BlocControle" << endl;
	#endif
	typeContenu = _BLOCCONTROLE;
}

BlocControle::BlocControle(Bloc * bfils)
{
	#ifdef MAP
		cout << "Appel au constructeur de BlocControle(Bloc * bfils)" << endl;
	#endif
	blocFils = bfils;
	typeContenu = _BLOCCONTROLE;
}

Bloc* BlocControle::getBlocFils()
{
	#ifdef MAP
		cout << "Appel a la fonction get blocFils BlocControle" << endl;
	#endif
	return blocFils;
}

void BlocControle::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de BlocControle" << endl;
	#endif
    blocParent = blc;
}

int BlocControle::getSize()
{
	return blocFils->getSize();
}

string BlocControle::buildIR(CFG * cfg) {
	return "";
}
