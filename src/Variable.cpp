#include "Variable.h"

Variable::Variable()
{
}

Variable::Variable(Type t, std::string* n)
{
	type=t;
    nom=n;
}

void Variable::AddInfo(Type t, std::string* n)
{
    type=t;
    nom=n;
}
