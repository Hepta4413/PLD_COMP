#ifndef BLOC_H
#define BLOC_H

#include "Contenu.h"
#include "Variable.h"
#include <vector>
#include <map>
#include <string>

class Variable;
class BlocControle;
class Fonction;
class Contenu;

class Bloc
{
	public:
	Bloc();
	Bloc(std::vector<Contenu*> c, Fonction * f,std::map<std::string*,Variable*>* var, Bloc * blocParent);
	void AddContenu(Contenu* c);
	void AddDeclaration(Declaration* d);
	
	private:
	std::vector<Contenu*>* cont;
	Fonction * fonct;
	std::map<std::string*,Declaration*>* varbloc;
	Bloc * blocParent;
		
};

#endif
