#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Fonction.h"
#include "AppelFonct.h"
#include <map>
#include <string>
#include "CFG.h"

class Fonction;

using namespace std;

class Programme
{
	public:
	Programme();
	void addFonction(Fonction* f);
	void verifVariable();
	bool verifFonction(AppelFonct* af);
	string buildIR(CFG* cfg);

	protected:
	map<string,Fonction*>* fonctions;

};

#endif
