#include "DeclAffect.h"
#include <iostream>

using namespace std;

/*DeclAffect::DeclAffect()
{
	#ifdef MAP
		cout << "Appel au constructeur de DeclAffect()" << endl;
	#endif
	typeContenu = _DECLARATION;
  decl = NULL;
  affect = NULL;
}*/

DeclAffect::DeclAffect(Declaration * d)
{
	#ifdef MAP
		cout << "Appel au constructeur de DeclAffect(Declaration * d)" << endl;
	#endif
	typeContenu = _DECLARATION;
  decl = d;
  affect = NULL;
}

DeclAffect::DeclAffect(Declaration * d, Affectation* a)
{
	#ifdef MAP
		cout << "Appel au constructeur de DeclAffect(Declaration * d, Affectation* a)" << endl;
	#endif
	typeContenu = _DECLARATIONAFFECTATION;
  decl = d;
  affect = a;
}

Declaration* DeclAffect::getDeclaration(){
	#ifdef MAP
		cout << "Appel a la methode getDeclaration() de DeclAffect" << endl;
	#endif
  return decl;
}

Affectation* DeclAffect::getAffectation(){
	#ifdef MAP
		cout << "Appel a la methode getDeclaration() de DeclAffect" << endl;
	#endif
  return affect;
}
