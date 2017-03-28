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
	Bloc(std::vector<Contenu*>* c, Fonction * f,std::map<std::string*,Declaration*>* var, Bloc * blocParent);
	void AddContenu(Contenu* c);
	void AddDeclaration(Declaration* d);
	Declaration* RechercherDeclaration(string* nom);
	

	protected:
	vector<Contenu*>* cont;
	Fonction * fonct;
	std::map<std::string*,Declaration*>* varbloc;
	Bloc * blocParent;
		
};

#endif
