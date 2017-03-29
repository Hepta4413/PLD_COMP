#include "Fonction.h"
#include <iostream>

using namespace std;

Fonction::Fonction()
{
    arguments = new vector<Declaration*>();
}

Fonction::Fonction(Type t, std::string* n, std::vector<Declaration*>* arg, Bloc* b)
{
	arguments = arg;
    bloc = b;
    nom=n;
    type = t;

}

void Fonction::AddProg(Programme* p)
{
    if(arguments==NULL){
        arguments = new vector<Declaration*>();
    }
    prog=p;
}

std::string* Fonction::getNom()
{
	return nom;
}
