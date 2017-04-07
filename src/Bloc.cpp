#include "Bloc.h"
#include "BlocIf.h"
#include "BlocFor.h"
#include "BlocWhile.h"
#include "Declaration.h"
#include "ListeDeclaration.h"
#include "BlocControle.h"
#include "Fonction.h"
#include "AppelFonct.h"
#include "Programme.h"
#include "Enums.h"
#include "Return.h"
#include <iostream>
#include <typeinfo>
#include <vector>

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
	if(c->getTypeContenu()==_DECLARATION){
		vector<Declaration*>* listedecl = ((ListeDeclaration*) c)->getListeDeclaration();
		while (!listedecl->empty()){
			Declaration* declTmp = listedecl->back();
			declTmp->setBloc(this);
			cont->push_back(declTmp);
			AddDeclaration(declTmp);
			listedecl->pop_back();
		}
	}else
	{
		c->setBloc(this);
		cont->push_back(c);
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
	}else
	{
		cerr<<"Erreur redéclaration de la variable "<<d->getName()<<endl;
	}
}

void Bloc::setBlocParent(Bloc* bloc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de bloc" << endl;
	#endif
	blocParent=bloc;
}

void Bloc::setFonction(Fonction* fonction)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de bloc" << endl;
	#endif
	fonct=fonction;
}

Fonction* Bloc::getFonction()
{
	#ifdef MAP
		cout << "Appel a la fonction getFonction de bloc" << endl;
	#endif
	return fonct;
}

bool Bloc::getContientRetour()
{
	#ifdef MAP
		cout << "Appel a la fonction getContientRetour de bloc" << endl;
	#endif
	return contientRetour;
}

void Bloc::ParcoursContenu(){
	#ifdef MAP
		cout << "Appel a la fonction ParcoursContenu de bloc" << endl;
	#endif
	vector<Variable*> variables;
	Type t1;
	Type t2;
	Return* contenuRetour;
	for(auto contenu = cont->begin(); contenu != cont->end(); contenu++)
	{
		switch((*contenu)->getTypeContenu())
		{
			case _APPELFONCT :
			case _VAR :
			case _VARS :
			case _VARTAB :
			case _EXPR :
			case _OPUNAIRE :
			case _OPBINAIRE :
			case _AFFECTATION :
				analyseExpression(*contenu);
			break;

			case _RETURN :
				contenuRetour= ((Return*)(*contenu));
				contenuRetour->getExpression()->setBloc(this);
				analyseExpression(contenuRetour->getExpression());
				t1 = fonct->getTypeRetour();
				t2 = contenuRetour->getExpression()->getType();
				if(t1==VOID_T || t1==t2)
				{
				}else{
					#ifdef WAR
						cerr<<"Warning ligne "<<((Ligne*)(*contenu))->getLigne()<<" : "<<((Ligne*)(*contenu))->getColonne()
						<<" type de retour incorrect attendu "<<t1<<" trouvé "<<t2<<endl;
					#endif
				}
				contientRetour = true;
			break;

			case _BLOCIF :
				((BlocIf*)(*contenu))->setBloc(this);
				analyseExpression(((BlocIf*)(*contenu))->getCondition());
				((BlocIf*)(*contenu))->getBlocAlors()->ParcoursContenu();
				if(((BlocIf*)(*contenu))->elsePresent())
				{
					((BlocIf*)(*contenu))->getBlocSinon()->ParcoursContenu();
				}
				contientRetour|=((BlocIf*)(*contenu))->getContientRetour();
			break;
			case _BLOCFOR :
				((BlocFor*)(*contenu))->setBloc(this);
				analyseExpression(((BlocFor*)(*contenu))->getCondition());
				analyseExpression(((BlocFor*)(*contenu))->getInit());
				analyseExpression(((BlocFor*)(*contenu))->getIncre());
				((BlocFor*)(*contenu))->getBlocBoucle()->ParcoursContenu();
				contientRetour|=((BlocFor*)(*contenu))->getBlocBoucle()->getContientRetour();
			break;
			case _BLOCWHILE :
				((BlocWhile*)(*contenu))->setBloc(this);
				analyseExpression(((BlocWhile*)(*contenu))->getCondition());
				((BlocWhile*)(*contenu))->getBlocBoucle()->ParcoursContenu();
				contientRetour|=((BlocWhile*)(*contenu))->getBlocBoucle()->getContientRetour();
			break;
			default : break;
		}
	}
	for(auto mapElem = varbloc->begin(); mapElem != varbloc->end(); mapElem++)
	{
		Declaration* decl = (mapElem->second);
		if(!decl->getRvalue())
		{
			#ifdef WAR
				Ligne * ligne = (Ligne*)(decl);
				cerr<<"Warning ligne "<<ligne->getLigne()<<" : "
				<<ligne->getColonne()<<" la variable "<<*(decl->getName())<<" est déclarée mais jamais utilisée"<<endl;
			#endif
		}
	}
}

void Bloc::analyseExpression(Contenu* contenu)
{
	#ifdef MAP
		cout << "Appel a la fonction analyseExpression de bloc" << endl;
	#endif

	string* nom;
	Declaration* declarat;
	Ligne* ligne;
	vector<Variable*> variables;
	contenu->setBloc(this);
	variables = ((Expression*)contenu)->variableUtilise();
	for(auto var = variables.begin(); var != variables.end(); var++)
	{
		 nom = (*var)->getNom();
		 declarat=RechercherDeclaration(nom);
		 ligne = ((Ligne*)contenu);
		 
		if(declarat != NULL && (declarat->getLigne()< ligne->getLigne() ||
		(declarat->getLigne()== ligne->getLigne() &&
		declarat->getColonne()< ligne->getColonne())))
		{
			(*var)->setType(declarat->getDeclarationType());
			if(declarat->getLvalue() || ((*var)->getLvalue() && !(*var)->getRvalue()))
			{
				declarat->setLvalue(true);
				if((*var)->getRvalue())
				{
					declarat->setRvalue(true);
				}
				#ifdef MAP
					cout<<"pas d'erreur"<<endl;
				#endif
			}else{
				cerr<<"Erreur ligne "<<ligne->getLigne()<<" : "
			<<ligne->getColonne()<<" la variable "<<(*nom)<<" n'est pas affectée"<<endl;
			}
		}else{
			cerr<<"Erreur ligne "<<ligne->getLigne()<<" : "
			<<ligne->getColonne()<<" la variable "<<(*nom)<<" n'est pas déclarée"<<endl;
		}
	}
	((Expression*)contenu)->calculType();
}

Declaration* Bloc::RechercherDeclaration(string* nom){
	#ifdef MAP
		cout << "Appel a la fonction RechercherDeclaration de bloc" << endl;
	#endif
	if(varbloc->find(*nom) == varbloc->end())
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
		map<string,Declaration*> map = *varbloc;
		return map[*nom];
	}
}

int Bloc::getSize()
{
	#ifdef MAP
		cout << "Appel a la fonction getSize de bloc" << endl;
	#endif
	
	int size = varbloc->size();
	for(unsigned int i=0; i<cont->size(); i++)
	{
		size += cont->at(i)->getSize();
	}
	return size;
}

string Bloc::buildIR(CFG* cfg)
{
	#ifdef MAP
		cout << "Appel a la fonction buildIR de bloc" << endl;
	#endif
	
	for(unsigned int i = 0 ; i< cont->size() ; i ++)
	{
		cont->at(i)->buildIR(cfg);
	}
	
	return "ok";
}
