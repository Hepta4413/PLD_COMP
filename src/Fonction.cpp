#include "Fonction.h"

Fonction::Fonction()
{
}

Fonction::Fonction(Type t, std::string nom, vector<Variable> arg, Bloc b)
{
	arguments = arg;
    bloc = b;
    this.nom=nom;
    type = t;
}

Fonction::AddProg(Programme* p)
{
    prog=p;
}
