#ifndef FONCTION_H
#define FONCTION_H

#include "Variable.h"
#include "Bloc.h"
#include "Enums.h"
#include <string>
#include <vector>

class Variable;
class Programme;

class Fonction
{
	public:
	Fonction();
	Fonction(Type* t, std::string* nom, std::vector<Variable>* arg, Bloc* b);
	void AddProg(Programme* p);
	std::string getNom();
	
	protected:
	std::string* nom;
	std::vector<Variable>* arguments;

	Programme * prog;
	Bloc* bloc;
	Type* type;
};

#endif
