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
	Bloc(std::vector<Contenu> c, Fonction * f,std::map<std::string,Variable> var, BlocControle * bControleParent);
	void AddContenu(Contenu c);
	
	private:
	std::vector<Contenu> cont;
	Fonction * fonct;
	std::map<std::string,Variable> varbloc;
	BlocControle * blocControleParent;
		
};

#endif
