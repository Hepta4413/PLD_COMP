#include "Bloc.h"

using namespace std;

Bloc::Bloc()
{
	blocParent=NULL;
}

Bloc::Bloc(std::vector<Contenu*>* c, Fonction * f, std::map<std::string*,Declaration*>* var, Bloc * bParent)
{
	cont = c;
	fonct = f;
	varbloc = var;
	blocParent = bParent;
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
        //std::map<std::string*,Declaration*> map = *varbloc;
        *(varbloc)[d->getName()]=d;
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
		return varbloc[nom];
	}
}
