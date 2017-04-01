#include "Contenu.h"
#include "../include/Contenu.h"
#include <iostream>

using namespace std;

Contenu::Contenu()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Contenu" << endl;
	#endif
}

Contenu::Contenu(Bloc * b)
{
	#ifdef MAP
		cout << "Appel au constructeur de Contenu(Bloc * b)" << endl;
	#endif
    blocParent = b;
}

Bloc* Contenu::getBloc()
{
	#ifdef MAP
		cout << "Appel a la fonction getBloc de Contenu" << endl;
	#endif
    return blocParent;
}

void Contenu::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de Contenu" << endl;
	#endif
    blocParent = blc;
}

TypeContenu Contenu::getTypeContenu() {
	#ifdef MAP
		cout << "Appel a la fonction getTypeContenu de Contenu" << endl;
		cout << typeContenu << endl;
	#endif
	return typeContenu;
}
