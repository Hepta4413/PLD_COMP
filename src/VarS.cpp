#include "VarS.h"
#include <iostream>

using namespace std;

VarS::VarS()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de VarS" << endl;
	#endif
	typeContenu = _VARS;
}

VarS::VarS(string* n)
{
	#ifdef MAP
		cout << "Appel au constructeur vide de VarS(string* n)" << endl;
	#endif
    nom=n;
    VerifDeclaration(nom);
}
