#include "VarTab.h"

VarTab::VarTab()
{
}

VarTab::VarTab(string* n, Expression* t, bool size)
{
	nom=n;
  valeur=t;
	taille=size;
}

VarTab::VarTab(Expression* t, bool size)
{
  valeur=t;
	taille=size;
}
