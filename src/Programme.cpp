#include "Programme.h"

Programme::Programme()
{
}

Programme::Programme(map<std::string,Fonction> f)
{
	fonctions = f;
}

Programme::AddFonction(Fonction f)
{
    fonctions.insert ( std::pair<string,Fonction>(f.nom,f) );
}
