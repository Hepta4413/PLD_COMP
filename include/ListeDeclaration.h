#ifndef LISTEDECLARATION_H
#define LISTEDECLARATION_H

#include <vector>
#include "Ligne.h"
#include "DeclAffect.h"

using namespace std;

class ListeDeclaration : public Ligne
{
	public:
	ListeDeclaration();
	ListeDeclaration(vector<DeclAffect*>* liste);
    vector<DeclAffect*>* getListeDeclaration() const { return listeDeclarations;};

	protected:
    vector<DeclAffect*>* listeDeclarations;

};

#endif
