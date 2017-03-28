#include "Const.h"

Const::Const()
{
}

Const::Const(long value)
{
	this->value=value;
}

long Const::getValue()
{
	return value;
}
