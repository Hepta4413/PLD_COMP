#include "Programme.h"

using namespace std;

Programme::Programme()
{
	fonctions = new map<string,Fonction>();
}

Programme::Programme(std::map<std::string,Fonction>* f)
{
	fonctions = f;
}

void Programme::AddFonction(Fonction* f)
{
	if(fonctions==NULL){	
		fonctions = new map<string,Fonction>();
	}
    f->AddProg(this);
    fonctions->insert ( std::pair<std::string,Fonction>(f->getNom(),*f) );
}
