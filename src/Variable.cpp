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
	typeContenu = _VAR;
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
	typeContenu = _VAR;
}

vector<Variable*> Variable::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de variable" << endl;
	#endif
	vector<Variable*> result;
	result.push_back(this);
	return result;
}

string* Variable::getNom()
{
	#ifdef MAP
		cout << "Appel a la fonction getNom de variable" << endl;
	#endif
	return nom;
}

bool Variable::getLvalue()
{
	#ifdef MAP
		cout << "Appel a la fonction getLvalue de variable" << endl;
	#endif
	return lvalue;
}

void Variable::setLvalue(bool lval)
{
	#ifdef MAP
		cout << "Appel a la fonction setLvalue de variable" << endl;
	#endif
	lvalue=lval;
}
