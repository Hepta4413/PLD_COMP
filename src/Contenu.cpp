#include "Contenu.h"

Contenu::Contenu()
{
}

Contenu::Contenu(Bloc * b)
{
	blocParent = b;
}

Bloc* getBloc()
{
    return blocParent;
}

void setBloc(Bloc* blc)
{
    blocParent = blc;
}
