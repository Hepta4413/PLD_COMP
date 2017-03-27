#include "Fonction.h"

using namespace std;

Fonction::Fonction()
{
    arguments = new vector<Variable*>();
}

Fonction::Fonction(Type t, std::string* n, std::vector<Variable*>* arg, Bloc* b)
{
	arguments = arg;
    bloc = b;
    nom=n;
    type = t;
}

void Fonction::AddProg(Programme* p)
{
    if(arguments==NULL){
        arguments = new vector<Variable*>();
    }
    prog=p;
}

std::string* Fonction::getNom()
{
	return nom;
}
