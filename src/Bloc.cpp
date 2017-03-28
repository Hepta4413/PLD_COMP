#include "Bloc.h"
#include "Declaration.h"
#include "BlocControle.h"
#include "Fonction.h"

using namespace std;

Bloc::Bloc()
{
	blocParent=NULL;
}

Bloc::Bloc(std::vector<Contenu*>* c, Fonction * f, std::map<string*,Declaration*>* var, Bloc * bParent)
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
        varbloc->insert ( std::pair<string*,Declaration*>(d->getName(),d));
        //*(varbloc[d->getName()]=d;
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
        std::map<string*,Declaration*> map = *varbloc;
        return map[nom];
	}
}
