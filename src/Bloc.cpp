#include "Bloc.h"
#include "Declaration.h"
#include "BlocControle.h"
#include "Fonction.h"
#include "Enums.h"
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

void Bloc::ParcoursContenu(){
	#ifdef MAP
		cout << "Appel a la fonction ParcoursBloc de bloc" << endl;
	#endif
	string* nom;
	Declaration* declarat;
	Ligne* ligne;
	for(auto contenu = cont->begin(); contenu != cont->end(); cont++) {
		switch((*contenu)->getTypeContenu())
		{
			case _VAR : 
			case _VARS :
			case _VARTAB :
				 nom = ((Variable*)(*contenu))->getNom();
				 declarat=RechercherDeclaration(nom);
				 ligne = ((Ligne*)(*contenu));
				if(declarat != NULL && (declarat->getLigne()> ligne->getLigne() ||
				(declarat->getLigne()== ligne->getLigne() && 
				declarat->getColonne()> ligne->getColonne()))){
					
				}else{
					cerr<<"Erreur ligne "<<ligne->getLigne()<<" : "
					<<ligne->getColonne()<<" la variable n'est pas déclarée"<<endl;
				}
			break;
			case _BLOCCONTROLE :
			case _BLOCIF :
			case _BLOCFOR :
			case _BLOCWHILE :
				((BlocControle*)(*contenu))->getBlocFils()->ParcoursContenu();
			break;
			default : break;
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


