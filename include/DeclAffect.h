#ifndef DECLAFFECT_H
#define DECLAFFECT_H

#include <vector>
#include "Ligne.h"
#include "Declaration.h"
#include "Affectation.h"

using namespace std;

class DeclAffect : public Ligne
{
	public:
	DeclAffect();
	DeclAffect(Declaration * d);//Pour Declaration
	DeclAffect(Declaration * d, Affectation* a);//Pour Declaration + Affectation
  Declaration* getDeclaration();
  Affectation* getAffectation();

	protected:
  Declaration* decl;
  Affectation* affect;

};

#endif
