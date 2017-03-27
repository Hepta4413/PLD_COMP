#include "Declaration.h"

Declaration::Declaration()
{
}

Declaration::Declaration(Type* t, std::string* n)
{
	type = t;
	name = n;
}
