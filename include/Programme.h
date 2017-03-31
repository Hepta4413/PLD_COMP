#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Fonction.h"
#include <map>
#include <string>

class Fonction;

using namespace std;

class Programme
{
	public:
	Programme();
	Programme(map<string*,Fonction*>* f);
	void AddFonction(Fonction* f);
	void VerifVariable();

	protected:
	map<string*,Fonction*>* fonctions;

};

#endif
