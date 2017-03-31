#ifndef FONCTION_H
#define FONCTION_H

#include "Declaration.h"
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
	Fonction(Type t, std::string* nom,std::vector<Declaration*>* arg, Bloc* b);
	void AddProg(Programme* p);
	std::string* getNom();
	int getSize();
	
	protected:
	std::string* nom;
	std::vector<Declaration*>* arguments;

	Programme * prog;
	Bloc* bloc;
	Type type;
};

#endif
