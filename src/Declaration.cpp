#include "Declaration.h"
#include <iostream>

using namespace std;

Declaration::Declaration()
{
	tailleTab=NULL;
}

Declaration::Declaration(Expression* taille)
{
	tailleTab = taille;
}

Declaration::Declaration(Type t, string* n)
{
	type = t;
	name = n;
	if(blocParent != NULL) {
		blocParent->AddDeclaration(this);
	}

}

string* Declaration::getName()
{
	return name;
}

Type Declaration::getDeclarationType()
{
	return type;
}

void Declaration::setBlocDeclaration(Bloc* b) {
	b->AddDeclaration(this);
	blocParent = b;
}

void Declaration::AddInfos(Type t, string* n)
{
	type = t;
	name = n;

	if(tailleTab!=NULL && (type==INT32TAB_T || type==INT64TAB_T || type==CHARTAB_T))
	{
		blocParent->AddContenu(new OPBinaire(new VarS(n),tailleTab, EQUAL_OB));
		tailleTab=NULL;
	}
}
