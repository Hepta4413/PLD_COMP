#include "Fonction.h"
#include <iostream>

using namespace std;

Fonction::Fonction()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Fonction" << endl;
	#endif
  arguments = new vector<Declaration*>();
}

Fonction::Fonction(Type t, string* n, vector<Declaration*>* arg, Bloc* b)
{
	#ifdef MAP
		cout << "	Appel au constructeur de Fonction(Type t, string* n, vector<Declaration*>* arg, Bloc* b)" << endl;
	#endif
	if(arg==NULL){
		arguments = new vector<Declaration*>();
	}
	else
	{
		arguments = arg;
	}
  bloc = b;   
  b->setFonction(this);
  nom=n;
  type = t;
  if(arg!=NULL && arg->size()>0){  
	  for(auto d = arguments->begin(); d != arguments->end(); d++) {
		(*d)->setBlocDeclaration(bloc);
	  }
	}   
}

void Fonction::AddProg(Programme* p)
{
	#ifdef MAP
		cout << "Appel a la fonction AddProg de Fonction  " <<this<< endl;
	#endif
	prog=p;
}

string* Fonction::getNom()
{
	#ifdef MAP
		cout << "Appel a la fonction getNom de Fonction" << endl;
	#endif
  return nom;
}

Bloc* Fonction::getBloc()
{
	#ifdef MAP
		cout << "Appel a la fonction getBloc de Fonction " << endl;
	#endif
  return bloc;
}

Type Fonction::getTypeRetour()
{
	#ifdef MAP
		cout << "Appel a la fonction getTypeRetour de Fonction " <<endl;
	#endif
  return type;
}

Programme* Fonction::getProgramme()
{
	#ifdef MAP
		cout << "Appel a la fonction getProgramme de Fonction "<<this << endl;
	#endif
	return prog;
}

vector<Declaration*>* Fonction::getArguments()
{
	#ifdef MAP
		cout << "Appel a la fonction getArguments de Fonction" << endl;
	#endif
  return arguments;
}
	
