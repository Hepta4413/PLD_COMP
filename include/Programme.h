#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Fonction.h"
#include "AppelFonct.h"
#include "CFG.h"
#include <map>
#include <string>

using namespace std;

class Programme
{
	public:
	Programme();
	void addFonction(Fonction* f);
	void verifVariable();
	bool verifFonction(AppelFonct* af);
	map<string,Fonction*>* getFonctions();

	protected:
	map<string,Fonction*>* fonctions;

};

#endif
