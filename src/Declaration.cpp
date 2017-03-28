#include "Declaration.h"

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
	blocParent->AddDeclaration(this);
}

void Declaration::AddInfos(Type t, string* n)
{
	type = t;
	name = n;
	if(tailleTab!=NULL && (type==INT32TAB_T || type==INT64TAB_T || type==CHARTAB_T){
		blocPArent->AddContenu(new VarS(n,tailleTab));
		tailleTab=NULL;
	}
}
