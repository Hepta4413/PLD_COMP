#include "VarTab.h"

VarTab::VarTab()
{
}

VarTab::VarTab(std::string n, int64_t[] val, Type t)
{
	nom=n;
	valueint=val;
	type=t;
}

VarTab::VarTab(std::string n, char[] val)
{
	nom=n;
	valuechar=val;
	type=CHAR;
}
