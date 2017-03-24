#include "Programme.h"

Programme::Programme()
{
}

Programme::Programme(std::map<std::string,Fonction> f)
{
	fonctions = f;
}

void Programme::AddFonction(Fonction f)
{
    f.AddProg(this);
    fonctions.insert ( std::pair<std::string,Fonction>(f.getNom(),f) );
}
