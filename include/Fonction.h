#ifndef FONCTION_H
#define FONCTION_H

#include "Declaration.h"
#include "Bloc.h"
#include "Enums.h"
#include <string>
#include <vector>
#include "Variable.h"

using namespace std;

class Programme;
class CFG;

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
	string buildIR(CFG* cfg);

	protected:
	string* nom;
	vector<Declaration*>* arguments;
	Programme * prog;
	Bloc* bloc;
	Type type;
};

#endif
