#include "Programme.h"
#include <iostream>

using namespace std;

Programme::Programme()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Programme" << endl;
	#endif
	fonctions = new map<string,Fonction>();
}

Programme::Programme(map<string,Fonction>* f)
{
	#ifdef MAP
		cout << "Appel au constructeur de Programme(map<string,Fonction>* f)" << endl;
	#endif
	fonctions = f;
}

void Programme::AddFonction(Fonction* f)
{
	#ifdef MAP
		cout << "Appel a la fonction addFonction de programme" << endl;
	#endif
	if(fonctions==NULL){
		fonctions = new map<string,Fonction>();
	}
    f->AddProg(this);
    fonctions->insert ( pair<string,Fonction>(*(f->getNom()),*f) );
}

	void VerifVariable(){
		
	}
