#ifndef FONCTION_H
#define FONCTION_H

#include "Variable.h"
#include "Programme.h"
#include "Bloc.h"
#include "Enums.h"
#include <string>
#include <vector>

class Variable;

class Fonction
{
	public:
	Fonction();
	Fonction(Type t, std::string nom, vector<Variable> arg, Bloc b);
	void AddProg(Programme* p);
	
	private:
	std::string nom;
	vector<Variable> arguments;
	Programme prog;
	Bloc bloc;
	Type type;
};

#endif
