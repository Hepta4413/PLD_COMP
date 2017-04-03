#ifndef LISTEDECLARATION_H
#define LISTEDECLARATION_H

#include <vector>
#include "Ligne.h"
#include "Declaration.h"

using namespace std;

class ListeDeclaration : public Ligne
{
	public:
	ListeDeclaration();
	ListeDeclaration(vector<Declaration*>* liste);
    vector<Declaration*>* getListeDeclaration() const { return listeDeclarations;};

	protected:
    vector<Declaration*>* listeDeclarations;

};

#endif
