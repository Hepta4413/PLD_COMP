#include "BlocFor.h"

BlocFor::BlocFor()
{
}

BlocFor::BlocFor(Expression c, Expression ini, Expression inc)
{
	condition = c;
	init = ini;
	incre = inc;
}
