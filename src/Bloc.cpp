#include "Bloc.h"

Bloc::Bloc()
{
}

Bloc::Bloc(Contenu c, Fonction f,Variable[] var, Bloc bControleParent)
{
	cont = c;
	fonct = f;
	varbloc = var;
	blocControleParent = bControleParent;
}
