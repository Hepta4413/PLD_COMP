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
	rvalue=true;
}

VarS::VarS(string* n)
{
	#ifdef MAP
		cout << "Appel au constructeur de VarS(string* n)" << endl;
	#endif
    nom=n;
	typeContenu = _VARS;
	lvalue=false;
	rvalue=true;
}

string VarS::buildIR(CFG * cfg) {
<<<<<<< HEAD
	#ifdef MAP
		cout << "Appel au constructeur de buildIR" << endl;
	#endif
	
	return "";
=======
	return Variable::buildIR(cfg);
>>>>>>> 2c495bb1f573e1f5941f960b8f1c860c2b78d079
}
