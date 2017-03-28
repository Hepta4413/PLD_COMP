#include "Bloc.h"

using namespace std;

Bloc::Bloc()
{
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
    c->blocParent = this;
}

void Bloc::AddDeclaration(Declaration* d)
{
	if (varbloc.find(d->name) == varbloc.end())
	{
		varbloc[d->name]=d;
	}
}
