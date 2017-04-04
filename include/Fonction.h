#ifndef FONCTION_H
#define FONCTION_H

#include "Declaration.h"
#include "Bloc.h"
#include "Enums.h"
#include <string>
#include <vector>

using namespace std;

class Variable;
class Programme;

class Fonction
{
	public:
	Fonction();
	Fonction(Type t, string* nom,vector<Declaration*>* arg, Bloc* b);
	void AddProg(Programme* p);
	string* getNom();
	Bloc* getBloc();
	Programme* getProgramme();
	vector<Declaration*>* getArguments();
	Type getTypeRetour();
	int getSize();

	protected:
	string* nom;
	vector<Declaration*>* arguments;
	Programme * prog;
	Bloc* bloc;
	Type type;
};

#endif
