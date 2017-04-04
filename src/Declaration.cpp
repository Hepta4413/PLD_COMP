#include "Declaration.h"
#include "OPBinaire.h"
#include "VarS.h"
#include <iostream>

using namespace std;

Declaration::Declaration()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Declaration" << endl;
	#endif
	tailleTab=NULL;
	typeContenu = _DECLARATION;
	lvalue=false;
	rvalue=false;
}

Declaration::Declaration(Expression* taille)
{
	#ifdef MAP
		cout << "Appel au constructeur de Declaration(Expression* taille)" << endl;
	#endif
	tailleTab = taille;
	typeContenu = _DECLARATION;
	lvalue=false;
	rvalue=false;
}

Declaration::Declaration(Type t, string* n)
{
	#ifdef MAP
		cout << "Appel au constructeur de Declaration(Type t, string* n)" << endl;
	#endif
	type = t;
	name = n;
	typeContenu = _DECLARATION;
	if(blocParent != NULL) {
		printf("declaration blocparent null");
		blocParent->AddDeclaration(this);
	}
	lvalue=false;
	rvalue=false;
}

string* Declaration::getName()
{
	#ifdef MAP
		cout << "Appel a la fonction getName de Declaration" << endl;
	#endif
	return name;
}

Type Declaration::getDeclarationType()
{
	#ifdef MAP
		cout << "Appel a la fonction getDeclarationType de Declaration" << endl;
	#endif
	return type;
}

void Declaration::setBlocDeclaration(Bloc* b) {
	#ifdef MAP
		cout << "Appel a la fonction setBlocDeclaration de Declaration" << endl;
	#endif
	b->AddDeclaration(this);
	blocParent = b;
}

void Declaration::setLvalue(bool b) {
	#ifdef MAP
		cout << "Appel a la fonction setLvalue de Declaration" << endl;
	#endif
	lvalue=b;
}

bool Declaration::getLvalue() {
	#ifdef MAP
		cout << "Appel a la fonction getLvalue de Declaration" << endl;
	#endif
	return lvalue;
}

void Declaration::setRvalue(bool b) {
	#ifdef MAP
		cout << "Appel a la fonction setRvalue de Declaration" << endl;
	#endif
	rvalue=b;
}

bool Declaration::getRvalue() {
	#ifdef MAP
		cout << "Appel a la fonction getRvalue de Declaration" << endl;
	#endif
	return rvalue;
}

void Declaration::AddInfos(Type t, string* n)
{
	#ifdef MAP
		cout << "Appel a la fonction AddInfos de Declaration" << endl;
	#endif
	type = t;
	name = n;

	#ifdef MAP
		cout << "Infos added : " << endl;
		cout << type << endl;
		cout << *name << endl;
	#endif

	if(tailleTab!=NULL && (type==INT32TAB_T || type==INT64TAB_T || type==CHARTAB_T))
	{
		blocParent->AddContenu(new OPBinaire(new VarS(n),tailleTab, EQUAL_OB));
		tailleTab=NULL;
	}

}

void Declaration::AddName(string* n) {
	#ifdef MAP
		cout << "Appel a la fonction AddName de Declaration" << endl;
	#endif

	name = n;

	#ifdef MAP
		cout << "Infos added : " << endl;
		cout << *name << endl;
	#endif
}

string Declaration::buildIR(CFG * cfg) {
	return "";
}
