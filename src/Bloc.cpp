#include "Bloc.h"

using namespace std;

Bloc::Bloc()
{
}

Bloc::Bloc(vector<Contenu*>* c, Fonction * f, map<string*,Variable*>* var, BlocControle * bControleParent)
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
