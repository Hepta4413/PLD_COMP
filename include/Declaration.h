#ifndef DECLARATION_H
#define DECLARATION_H

#include "Ligne.h"
#include "Enums.h"
#include <string.h>

class Declaration : public Ligne
{
	public:
	Declaration();
	Declaration(Type t, std::string name);
	
	private:
	Type type;
	std::string name;
		
};

#endif
