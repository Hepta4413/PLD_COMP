#ifndef BLOC_H
#define BLOC_H

#include "Enums.h"
#include <vector>
#include <map>
#include <string>
#include "Contenu.h"
#include "Variable.h"
#include "BlocControle.h"

class Fonction;
class CFG;
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
	bool getContientRetour();
	int getSize();
	string buildIR(CFG* cfg);

	protected:
	vector<Contenu*>* cont;
	Fonction * fonct;
	map<string,Declaration*>* varbloc;
	Bloc * blocParent;
	bool contientRetour;

};

#endif
