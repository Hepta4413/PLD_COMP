#include "VarTab.h"

VarTab::VarTab()
{
}

VarTab::VarTab(std::string n, int t, bool ta)
{
	nom=n;
    valeur=t;
	taille=ta;
}

VarTab::VarTab(int t, bool ta)
{
    valeur=t;
	taille=ta;
}
