#include "Declaration.h"

using namespace std;

Declaration::Declaration()
{
}

Declaration::Declaration(Type t, string* n)
{
	type = t;
	name = n;
}
