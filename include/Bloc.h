#ifndef BLOC_H
#define BLOC_H

#include "OPBinaire.h"
#include "Enums.h"
#include <vector>
#include <map>
#include <string>

class Variable;
class BlocControle;
class Fonction;
class Contenu;
class Declaration;

using namespace std;

class Bloc
{
	public:
	Bloc();
	void AddContenu(Contenu* c);
	void AddDeclaration(Declaration* d);
	void ParcoursContenu();
	Declaration* RechercherDeclaration(string* nom);
	void setBlocParent(Bloc* bloc);
	void setFonction(Fonction* fonction);
	Fonction* getFonction();
	void analyseExpression(Contenu* expr);

	protected:
	vector<Contenu*>* cont;
	Fonction * fonct;
	map<string,Declaration*>* varbloc;
	Bloc * blocParent;

};

#endif
