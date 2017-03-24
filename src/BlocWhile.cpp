#include "BlocWhile.h"

BlocWhile::BlocWhile()
{
}

BlocWhile::BlocWhile(Expression e, Bloc bloc)
{
	condition = e;
    boucle=bloc;
}
