#include "BlocIf.h"

BlocIf::BlocIf()
{
}

BlocIf::BlocIf(Bloc* bloc)
{
    sinon = bloc;
}

void BlocIf::AddIf(Expression* expr, Bloc* bloc)
{
    si = expr;
    alors = bloc;
}
