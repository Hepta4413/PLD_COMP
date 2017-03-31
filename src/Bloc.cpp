#include "Bloc.h"
#include "Declaration.h"
#include "BlocControle.h"
#include "Fonction.h"
#include <iostream>
#include <typeinfo>

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
	c->setBloc(this);
	cont->push_back(c);
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

Declaration* Bloc::RechercherDeclaration(){
	#ifdef MAP
		cout << "Appel a la fonction RechercherDeclaration de bloc" << endl;
	#endif
	for(auto contenu = cont->begin(); contenu != cont->end(); d++) {
		switch(contenu->getTypeContenu())
		{
			case _VAR : 
			case _VARS :
			case _VARTAB :
				nom = (Variable*)contenu->nom;
				RechercherDeclaration(nom);
			break;
			case _BLOCCONTROLE :
			case _BLOCIF :
			case _BLOCFOR :
			case _BLOCWHILE :
				(BlocControle*)contenu->getBlocFils()->RechercherDeclaration();
			break;
		}	 
	}
}

Declaration* Bloc::RechercherDeclaration(string* nom){
	if(varbloc->find(nom) == varbloc->end())
	{
		if(blocParent!=NULL)
		{
			return blocParent->RechercherDeclaration(nom);
		}
		else
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


