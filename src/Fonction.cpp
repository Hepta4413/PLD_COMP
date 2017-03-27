#include "Fonction.h"

Fonction::Fonction()
{
}

Fonction::Fonction(Type* t, std::string* n, std::vector<Variable>* arg, Bloc* b)
{
	arguments = arg;
    bloc = b;
    nom=n;
    type = t;
}

void Fonction::AddProg(Programme* p)
{
    prog=p;
}

std::string Fonction::getNom()
{
	return nom;
}
