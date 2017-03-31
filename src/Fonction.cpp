#include "Fonction.h"
#include <iostream>

using namespace std;

Fonction::Fonction()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Fonction" << endl;
	#endif
  printf("new empty fonction");
  arguments = new vector<Declaration*>();
}

Fonction::Fonction(Type t, string* n, vector<Declaration*>* arg, Bloc* b)
{
	#ifdef MAP
		cout << "Appel au constructeur de Fonction(Type t, string* n, vector<Declaration*>* arg, Bloc* b)" << endl;
	#endif
  arguments = arg;
  bloc = b;   
  nom=n;
  type = t;
  cout<<arg<<endl;
  if(arg!=NULL && arg->size()>0){  
	  for(auto d = arguments->begin(); d != arguments->end(); d++) {
		(*d)->setBlocDeclaration(bloc);
	  }
	}   
}

void Fonction::AddProg(Programme* p)
{
	#ifdef MAP
		cout << "Appel a la fonction AddProg de Fonction" << endl;
	#endif
  printf("add prog");
  if(arguments==NULL){
    arguments = new vector<Declaration*>();
  }
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
		cout << "Appel a la fonction getBloc de Fonction" << endl;
	#endif
  return bloc;
}
