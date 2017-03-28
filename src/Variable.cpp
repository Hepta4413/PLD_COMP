#include "Variable.h"

Variable::Variable()
{
}

void Variable::VerifDeclaration(string* nom)
{
	Declaration* decl = RechercherDeclaration(nom);
    if(decl==NULL){
		cerr<<"Erreur la variable "<<*n<<" n'est pas déclarée"<<endl;
	}else{
		type=decl->getDeclarationType();
	}
}

