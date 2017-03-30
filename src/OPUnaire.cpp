#include "OPUnaire.h"
#include <iostream>

using namespace std;

OPUnaire::OPUnaire()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de OPUnaire" << endl;
	#endif
}

OPUnaire::OPUnaire(Expression* e, Opunaire ope)
{
	#ifdef MAP
		cout << "Appel au constructeur de OPUnaire(Expression* e, Opunaire ope)" << endl;
	#endif
	exp = e;
	op = ope;
}
