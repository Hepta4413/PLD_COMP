#include "Bloc.h"
#include "Declaration.h"
#include "BlocControle.h"
#include "Fonction.h"
#include <iostream>

using namespace std;

Bloc::Bloc()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Bloc" << endl;
	#endif
	blocParent=NULL;
	cont = new vector<Contenu*>();
	varbloc = new map<string*, Declaration*>();
}

void Bloc::AddContenu(Contenu* c)
{
	#ifdef MAP
		cout << "Appel a la fonction AddContenu de bloc" << endl;
	#endif
	cont->push_back(c);
	c->setBloc(this);
}

void Bloc::AddDeclaration(Declaration* d)
{
	#ifdef MAP
		cout << "Appel a la fonction AddDeclaration de bloc" << endl;
	#endif
	if (varbloc->find(d->getName()) == varbloc->end())
	{
		varbloc->insert ( pair<string*,Declaration*>(d->getName(),d));
	}
}

Declaration* Bloc::RechercherDeclaration(string* nom){
	#ifdef MAP
		cout << "Appel a la fonction RechercherDeclaration de bloc" << endl;
	#endif
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

int Bloc::getSize()
{
	int size = varbloc->size();
	for(unsigned int i=0; i<cont->size(); i++)
	{
		size += cont->at(i)->getSize();
	}
	return size;
}
