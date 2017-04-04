#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Fonction.h"
#include "AppelFonct.h"
#include <map>
#include <string>

class Fonction;

using namespace std;

class Programme
{
	public:
	Programme();
	void addFonction(Fonction* f);
	void verifVariable();
	bool verifFonction(AppelFonct* af);

	protected:
	map<string,Fonction*>* fonctions;

};

#endif
