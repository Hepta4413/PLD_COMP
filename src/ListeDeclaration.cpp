#include "ListeDeclaration.h"
#include <iostream>

using namespace std;

ListeDeclaration::ListeDeclaration()
{
	#ifdef MAP
		cout << "Appel au constructeur de ListeDeclaration()" << endl;
	#endif
	typeContenu = _DECLARATION;
    listeDeclarations = new vector<Declaration*>();
}

ListeDeclaration::ListeDeclaration(vector<Declaration*>* l)
{
	#ifdef MAP
		cout << "Appel au constructeur de ListeDeclaration(vector<Declaration*>* l)" << endl;
	#endif
	typeContenu = _DECLARATION;
    listeDeclarations = l;
}
