#include "Programme.h"
#include <iostream>

using namespace std;

Programme::Programme()
{
	fonctions = new map<string,Fonction>();
}

Programme::Programme(map<string,Fonction>* f)
{
	fonctions = f;
}

void Programme::AddFonction(Fonction* f)
{
	if(fonctions==NULL){
		fonctions = new map<string,Fonction>();
	}
    f->AddProg(this);
    fonctions->insert ( pair<string,Fonction>(*(f->getNom()),*f) );

}
