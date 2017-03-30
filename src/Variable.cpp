#include "Variable.h"
#include "Bloc.h"
#include "Declaration.h"
#include <iostream>

using namespace std;

Variable::Variable()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Variable" << endl;
	#endif
}

void Variable::VerifDeclaration(string* nom)
{
	#ifdef MAP
		cout << "Appel au constructeur de Variable(string* nom)" << endl;
	#endif
	Declaration* decl = blocParent->RechercherDeclaration(nom);
    if(decl==NULL){
		cerr<<"Erreur la variable "<<*nom<<" n'est pas déclarée"<<endl;
	}else{
		type=decl->getDeclarationType();
	}
}

