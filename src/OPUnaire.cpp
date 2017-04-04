#include "OPUnaire.h"
#include <iostream>

using namespace std;

OPUnaire::OPUnaire()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de OPUnaire" << endl;
	#endif
	typeContenu = _OPUNAIRE;
}

OPUnaire::OPUnaire(Expression* e, Opunaire ope)
{
	#ifdef MAP
		cout << "Appel au constructeur de OPUnaire(Expression* e, Opunaire ope)" << endl;
	#endif
	exp = e;
	op = ope;
	typeContenu = _OPUNAIRE;
}

vector<Variable*> OPUnaire::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de opUnaire" << endl;
	#endif
	return exp->variableUtilise();
}

Type OPUnaire::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction calculType de OPUnaire" << endl;
	#endif
	type=exp->calculType();
	return type;
}

string OPUnaire::buildIR(CFG * cfg) {
	return "";
}

void OPUnaire::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de OPUnaire" << endl;
	#endif
    blocParent = blc;
	exp->setBloc(blc);
}
