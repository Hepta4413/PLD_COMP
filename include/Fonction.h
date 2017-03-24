#ifndef FONCTION_H
#define FONCTION_H

#include "Variable.h"
#include "Programme.h"
#include <string>

class Variable;

class Fonction
{
	public:
	Fonction();
	Fonction(std::string nom, Variable arg[], Programme p);
	
	private:
	std::string nom;
	Variable[] arguments;
	Programme prog;
};

#endif
