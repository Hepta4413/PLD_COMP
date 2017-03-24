#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Fonction.h"
#include <map>
#include <string>

class Fonction;

class Programme
{
	public:
	Programme();
	Programme(std::map<std::string,Fonction> f);
	void AddFonction(Fonction f);
	
	private:
	std::map<std::string,Fonction> fonctions;
		
};

#endif
