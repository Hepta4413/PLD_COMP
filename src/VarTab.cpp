#include "VarTab.h"
#include <iostream>

using namespace std;

VarTab::VarTab()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de VarTab" << endl;
	#endif
	typeContenu = _VARTAB;
}

VarTab::VarTab(string* n, Expression* t)
{
	#ifdef MAP
		cout << "Appel au constructeur de VarTab(string* n, Expression* t)" << endl;
	#endif
	nom=n;
	indice=t;
	VerifDeclaration(nom);
}
