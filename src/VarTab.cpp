#include "VarTab.h"

VarTab::VarTab()
{
}

VarTab::VarTab(std::string n, int t, bool taille)
{
	nom=n;
    valeur=t;
	this.taille=taille;
}

VarTab::VarTab(int t, bool taille)
{
    valeur=t;
	this.taille=taille;
}
