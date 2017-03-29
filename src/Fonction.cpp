#include "Fonction.h"
#include <iostream>

using namespace std;

Fonction::Fonction()
{
  arguments = new vector<Declaration*>();
}

Fonction::Fonction(Type t, string* n, vector<Declaration*>* arg, Bloc* b)
{
  arguments = arg;
  bloc = b;
  nom=n;
  type = t;

  for(auto d = arguments->begin(); d != arguments->end(); d++) {
    (*d)->setBlocDeclaration(bloc);
  }
}

void Fonction::AddProg(Programme* p)
{
  if(arguments==NULL){
    arguments = new vector<Declaration*>();
  }
  prog=p;
}

string* Fonction::getNom()
{
  return nom;
}
