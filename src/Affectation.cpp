#include "Affectation.h"

Affectation::Affectation()
{
}

Affectation::Affectation(VarS vars, long value, Type t)
{
	this.vars = vars;
	valuei = value;
	type=t;
}

Affectation::Affectation(VarS vars, char value)
{
	this.vars = vars;
	valuec = value;
	type=CHAR;
}

Affectation::Affectation(VarTab vartab, long value, int i, Type t)
{
	this.vartab = vartab;
	valuei = value;
	index = i;
	type=t;
}

Affectation::Affectation(VarTab vartab, char value, int i)
{
	this.vartab = vartab;
	valuec = value;
	index = i;
	type=CHAR;
}

Affectation::Affectation(VarTab vartab, long value[], Type t)
{
	this.vartab = vartab;
	valuetabi = value;
	type=t;
}

Affectation::Affectation(VarTab vartab, char value[])
{
	this.vartab = vartab;
	valuetabc = value;
	type=CHAR;
}
