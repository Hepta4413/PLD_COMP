#include "VarTab.h"

VarTab::VarTab()
{
}

VarTab::VarTab(std::string n, int t, Type typ)
{
	nom=n;
    taille=t;
    type=typ;
}

VarTab::VarTab(int t)
{
    taille=t;
}
