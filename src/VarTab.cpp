#include "VarTab.h"

VarTab::VarTab()
{
}

VarTab::VarTab(string* n, Const* t, bool size)
{
	nom=n;
  valeur=t->getValue();
	taille=size;
}

VarTab::VarTab(long t, bool size)
{
  valeur=t;
	taille=size;
}
