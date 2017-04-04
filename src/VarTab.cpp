#include "VarTab.h"
#include <iostream>

using namespace std;

VarTab::VarTab()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de VarTab" << endl;
	#endif
	typeContenu = _VARTAB;
	lvalue=false;
	rvalue=true;
}

VarTab::VarTab(string* n, Expression* t)
{
	#ifdef MAP
		cout << "Appel au constructeur de VarTab(string* n, Expression* t)" << endl;
	#endif
	nom=n;
	indice=t;
	typeContenu = _VARTAB;
	lvalue=false;
	rvalue=true;
}

string VarTab::buildIR(CFG * cfg) {
	return "";
}
