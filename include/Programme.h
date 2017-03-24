#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Fonction.h"
#include <map>
#include <string>

class Programme
{
	public:
	Programme();
	Programme(map<std::string,Fonction> f);
	AddFonction(Fonction f);
	
	private:
	map<std::string,Fonction> fonctions;
		
};

#endif
