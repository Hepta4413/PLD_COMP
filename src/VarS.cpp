#include "VarS.h"
#include <iostream>

using namespace std;

VarS::VarS()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de VarS " <<this << endl;
	#endif
	typeContenu = _VARS;
	lvalue=false;
}

VarS::VarS(string* n)
{
	#ifdef MAP
		cout << "Appel au constructeur de VarS(string* n)" << endl;
	#endif
    nom=n;
	typeContenu = _VARS;
	lvalue=false;
}
