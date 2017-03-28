#include "Contenu.h"

Contenu::Contenu()
{
}

Contenu::Contenu(Bloc * b)
{
    blocParent = b;
}

Bloc* Contenu::getBloc()
{
    return blocParent;
}

void Contenu::setBloc(Bloc* blc)
{
    blocParent = blc;
}
