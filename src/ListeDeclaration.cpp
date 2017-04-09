#include "ListeDeclaration.h"
#include <iostream>

using namespace std;

ListeDeclaration::ListeDeclaration()
{
	#ifdef MAP
		cout << "Appel au constructeur de ListeDeclaration()" << endl;
	#endif
	typeContenu = _DECLARATIONAFFECTATION;
  listeDeclarations = new vector<DeclAffect*>();
}

ListeDeclaration::ListeDeclaration(vector<DeclAffect*>* l)
{
	#ifdef MAP
		cout << "Appel au constructeur de ListeDeclaration(vector<Declaration*>* l)" << endl;
	#endif
	typeContenu = _DECLARATIONAFFECTATION;
  listeDeclarations = l;
}
