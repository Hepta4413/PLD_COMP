#include "BlocFor.h"

BlocFor::BlocFor()
{
}

BlocFor::BlocFor(Expression* c, Expression* ini, Expression* inc, Bloc* bloc)
{
	condition = c;
	init = ini;
	incre = inc;
    boucle=bloc;
}
