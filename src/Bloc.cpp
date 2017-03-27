#include "Bloc.h"

Bloc::Bloc()
{
}

Bloc::Bloc(std::vector<Contenu*>* c, Fonction * f, std::map<std::string*,Variable*>* var, BlocControle * bControleParent)
{
	cont = c;
	fonct = f;
	varbloc = var;
	blocControleParent = bControleParent;
}

void Bloc::AddContenu(Contenu* c)
{
    cont->push_back(c);
}
