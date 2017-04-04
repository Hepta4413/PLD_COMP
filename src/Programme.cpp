#include "Programme.h"
#include <iostream>

using namespace std;

Programme::Programme()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Programme" << endl;
	#endif
	fonctions = new map<string,Fonction*>();
	Fonction* f1 = new Fonction(INT32_T,new string("getchar"),NULL,new Bloc()) ;
	vector<Declaration*>* argPut = new vector<Declaration*>();
	argPut->push_back(new Declaration(INT32_T,new string("")));
	Fonction* f2 = new Fonction(INT32_T,new string("putchar"),argPut,new Bloc()) ;
	fonctions->insert ( pair<string,Fonction*>(*(f1->getNom()),f1) );
	fonctions->insert ( pair<string,Fonction*>(*(f2->getNom()),f2) );
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
	  bool mainPresent=false;
	  for(auto fonct = fonctions->begin(); fonct != fonctions->end(); fonct++) {
		if(fonct->first!="putchar" && fonct->first!="getchar")
		{
			Fonction* fct = fonct->second;
			fct->getBloc()->ParcoursContenu();
			if(fct->getTypeRetour()!=VOID_T && !fct->getBloc()->getContientRetour())
			{
				cout << "Erreur dans la fonction "<<*(fct->getNom()) <<" absence de retour sur une des branches d'exécution"<< endl;
			}
			if(fonct->first=="main")
			{
				Type t = fct->getTypeRetour();
				if(t==VOID_T || t==INT32_T || t==INT64_T)
				{
					if(fct->getArguments()==NULL || fct->getArguments()->size()==0)
					{
						mainPresent=true;
					}else
					{
						cerr<<"Erreur argument du main invalide"<<endl;
					}
				}else
				{
					cerr<<"Erreur type de retour du main incorrect"<<endl;				
				}
			}
		}
	  }
	  if(!mainPresent)
	  {
		  cerr<<"Absence de main correct dans le programme"<<endl;				
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
		cout<<"taille incorect"<<endl;
	}
	return false;
}
