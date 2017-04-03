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
		cout << "	Appel a la fonction addFonction de programme " <<*(f->getNom())<< endl;
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
		cout<<param->size()<<" "<<paramAttendu->size()<<" "<<*(fonct->getNom())<<endl;
		if(param->size()==paramAttendu->size())
		{
			auto par = param->begin();
			auto parAttendu=paramAttendu->begin();
			int i=1;
			for(; par != param->end(); par++) 
			{
				Type t1 = (*par)->getType();
				Type t2 = (*parAttendu)->getDeclarationType();
				if(!(t1==CONSTVAL_T || t1==t2))
				{
					#ifdef WAR
						cerr<<"Warning ligne "<<af->getLigne()<<" : "
							<<af->getColonne()<<" arguments n°"<<i<<" d'un mauvais type, attendu "<<t1<<" trouvé "<<t2<<endl;
					#endif
				}
				parAttendu++;
				i++;
			}
			af->setFonctionAssocie(fonct);
			return true;
		}
	}
	return false;
}
