#include "Programme.h"
#include <iostream>

using namespace std;

Programme::Programme()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Programme" << endl;
	#endif
	fonctions = new map<string,Fonction*>();
}

Programme::Programme(map<string,Fonction*>* f)
{
	#ifdef MAP
		cout << "Appel au constructeur de Programme(map<string,Fonction>* f)" << endl;
	#endif
	fonctions = f;
}

void Programme::addFonction(Fonction* f)
{
	#ifdef MAP
		cout << "Appel a la fonction addFonction de programme" << endl;
	#endif
	if(fonctions==NULL){
		fonctions = new map<string,Fonction*>();
	}
    f->AddProg(this);
    fonctions->insert ( pair<string,Fonction*>(*(f->getNom()),f) );
}

void Programme::verifVariable(){
	#ifdef MAP
		cout << "Appel a la fonction Verifvariable de programme" << endl;
	#endif
	  for(auto fonct = fonctions->begin(); fonct != fonctions->end(); fonct++) {
		fonct->second->getBloc()->ParcoursContenu();
	  }
}

bool Programme::verifFonction(AppelFonct* af){
	#ifdef MAP
		cout << "Appel a la fonction verifFonction de programme" << endl;
	#endif
	if(fonctions->find(*(af->getNom()))!=fonctions->end())
	{
		map<string,Fonction*> mapFonction = *fonctions;
		Fonction* fonct = mapFonction[*(af->getNom())];
		vector<Declaration*>* paramAttendu = fonct->getArguments();
		vector<Expression*>* param = af->getParam();
		cout<<param<<" "<<paramAttendu<<endl;
		if(param->size()==paramAttendu->size())
		{
			return true;
		}
	}
	return false;
}
