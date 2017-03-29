#include "Bloc.h"
#include "Declaration.h"
#include "BlocControle.h"
#include "Fonction.h"
#include <iostream>

using namespace std;

Bloc::Bloc()
{
	blocParent=NULL;
	cont = new vector<Contenu*>();
	varbloc = new map<string*, Declaration*>();
}

void Bloc::AddContenu(Contenu* c)
{
	cont->push_back(c);
	c->setBloc(this);
}

void Bloc::AddDeclaration(Declaration* d)
{
	if (varbloc->find(d->getName()) == varbloc->end())
	{
		varbloc->insert ( pair<string*,Declaration*>(d->getName(),d));
	}
}

Declaration* Bloc::RechercherDeclaration(string* nom){
	if(varbloc->find(nom) == varbloc->end())
	{
		if(blocParent!=NULL)
		{
			return blocParent->RechercherDeclaration(nom);
		}else
		{
			return NULL;
		}
	}
	else
	{
		map<string*,Declaration*> map = *varbloc;
		return map[nom];
	}
}
