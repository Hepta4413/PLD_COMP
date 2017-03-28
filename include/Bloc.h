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

using namespace std;

class Bloc
{
	public:
	Bloc();
	Bloc(vector<Contenu*>* c, Fonction * f, map<string*, Variable*>* var, BlocControle * bControleParent);
	void AddContenu(Contenu* c);

	private:
	vector<Contenu*>* cont;
	Fonction * fonct;
	map<string*,Variable*>* varbloc;
	BlocControle * blocControleParent;

};

#endif
