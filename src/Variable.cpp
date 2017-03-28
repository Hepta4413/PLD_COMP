#include "Variable.h"
#include "Bloc.h"
#include "Declaration.h"
#include <iostream>

Variable::Variable()
{
}

void Variable::VerifDeclaration(string* nom)
{
	Declaration* decl = blocParent->RechercherDeclaration(nom);
    if(decl==NULL){
		cerr<<"Erreur la variable "<<*nom<<" n'est pas déclarée"<<endl;
	}else{
		type=decl->getDeclarationType();
	}
}

