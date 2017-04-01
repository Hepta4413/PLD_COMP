#include "Bloc.h"
#include "BlocIf.h"
#include "BlocFor.h"
#include "BlocWhile.h"
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
	varbloc = new map<string, Declaration*>();
}

void Bloc::AddContenu(Contenu* c)
{
	#ifdef MAP
		cout << "Appel a la fonction AddContenu de bloc " << this<<endl;
		cout << "Ajout du contenu "<<c<<" de type "<<c->getTypeContenu()<<" dans le bloc "<<this<<endl;
	#endif
	c->setBloc(this);
	cont->push_back(c);
	if(c->getTypeContenu()==_DECLARATION){
		AddDeclaration((Declaration*)c);
	}
}

void Bloc::AddDeclaration(Declaration* d)
{
	#ifdef MAP
		cout << "Appel a la fonction AddDeclaration de bloc" << endl;
	#endif
	if (varbloc->find(*(d->getName())) == varbloc->end())
	{
		varbloc->insert ( pair<string,Declaration*>(*(d->getName()),d));
	}
}

void Bloc::setBlocParent(Bloc* bloc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de bloc" << endl;
	#endif
	blocParent=bloc;
}

void Bloc::ParcoursContenu(){
	#ifdef MAP
		cout << "Appel a la fonction ParcoursContenu de bloc" << endl;
	#endif
	string* nom;
	Declaration* declarat;
	Ligne* ligne;
	vector<Variable*> variables;
	for(auto contenu = cont->begin(); contenu != cont->end(); contenu++) 
	{		
		switch((*contenu)->getTypeContenu())
		{
			case _VAR : 
			case _VARS :
			case _VARTAB :
			case _EXPR :
			case _OPUNAIRE :
			case _OPBINAIRE :
			case _AFFECTATION :
			case _APPELFONCT :
				variables = ((Expression*)(*contenu))->variableUtilise();
				for(auto var = variables.begin(); var != variables.end(); var++) 
				{		
					 nom = (*var)->getNom();
					 cout<<"this "<<this<< " et le parent "<<blocParent<<endl;
					 declarat=RechercherDeclaration(nom);
					 ligne = ((Ligne*)(*contenu));
					 cout<<"declaration "<<declarat<<endl;
					if(declarat != NULL && (declarat->getLigne()< ligne->getLigne() ||
					(declarat->getLigne()== ligne->getLigne() && 
					declarat->getColonne()< ligne->getColonne()))){
						if(declarat->getLvalue())
						{
							if(!(*var)->getLvalue())
							{
								declarat->setRvalue(true);
							}
							cout<<"pas d'erreur"<<endl;
						}else{
							cerr<<"Erreur ligne "<<ligne->getLigne()<<" : "
						<<ligne->getColonne()<<" la variable "<<(*nom)<<" n'est pas affectée"<<endl;
						}
					}else{						
						cerr<<"Erreur ligne "<<ligne->getLigne()<<" : "
						<<ligne->getColonne()<<" la variable "<<(*nom)<<" n'est pas déclarée"<<endl;
					}
				}
			break;
			case _BLOCIF :
				((BlocIf*)(*contenu))->getBlocAlors()->setBlocParent(this);
				((BlocIf*)(*contenu))->getBlocAlors()->ParcoursContenu();
				if(((BlocIf*)(*contenu))->elsePresent())
				{
					((BlocIf*)(*contenu))->getBlocSinon()->setBlocParent(this);
					((BlocIf*)(*contenu))->getBlocSinon()->ParcoursContenu();
				}
			break;
			case _BLOCFOR :
				((BlocFor*)(*contenu))->getBlocBoucle()->setBlocParent(this);
				((BlocFor*)(*contenu))->getBlocBoucle()->ParcoursContenu();
			break;				
			case _BLOCWHILE :
				((BlocWhile*)(*contenu))->getBlocBoucle()->setBlocParent(this);
				((BlocWhile*)(*contenu))->getBlocBoucle()->ParcoursContenu();
			break;
			default : break;
		}	 
	}
	for(auto mapElem = varbloc->begin(); mapElem != varbloc->end(); mapElem++) 
	{
		Declaration* decl = (mapElem->second);
		if(!decl->getRvalue())
		{
			Ligne * ligne = (Ligne*)(decl);
			cerr<<"Warning ligne "<<ligne->getLigne()<<" : "
			<<ligne->getColonne()<<" la variable "<<*(decl->getName())<<" est déclarée mais jamais utilisée"<<endl;
		}
	}
}

Declaration* Bloc::RechercherDeclaration(string* nom){
	#ifdef MAP
		cout << "Appel a la fonction RechercherDeclaration de bloc" << endl;
	#endif
	if(varbloc->find(*nom) == varbloc->end())
	{
		cout<<"Pas trouvé dans le bloc "<<this<<endl;
		cout<<blocParent<<endl;
		if(blocParent!=NULL)
		{
			cout<<"il y a un parent "<<this<<endl;
			return blocParent->RechercherDeclaration(nom);
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		map<string,Declaration*> map = *varbloc;
		return map[*nom];
	}
}


