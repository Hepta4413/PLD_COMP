#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Fonction.h"
#include <map>
#include <string>

using namespace std;

class Programme
{
	public:
	Programme();
	void addFonction(Fonction f);
	
	private:
	map<string,Fonction> fonctions;
		
};

#endif
