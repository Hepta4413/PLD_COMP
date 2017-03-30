#include "Declaration.h"
#include <iostream>

using namespace std;

Declaration::Declaration()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Declaration" << endl;
	#endif
	tailleTab=NULL;
}

Declaration::Declaration(Expression* taille)
{
	#ifdef MAP
		cout << "Appel au constructeur de Declaration(Expression* taille)" << endl;
	#endif
	tailleTab = taille;
}

Declaration::Declaration(Type t, string* n)
{
	#ifdef MAP
		cout << "Appel au constructeur de Declaration(Type t, string* n)" << endl;
	#endif
	type = t;
	name = n;
	if(blocParent != NULL) {
		printf("declaration blocparent null");
		blocParent->AddDeclaration(this);
	}

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

void Declaration::AddInfos(Type t, string* n)
{
	#ifdef MAP
		cout << "Appel a la fonction AddInfos de Declaration" << endl;
	#endif
	type = t;
	name = n;

	if(tailleTab!=NULL && (type==INT32TAB_T || type==INT64TAB_T || type==CHARTAB_T))
	{
		blocParent->AddContenu(new OPBinaire(new VarS(n),tailleTab, EQUAL_OB));
		tailleTab=NULL;
	}
}
