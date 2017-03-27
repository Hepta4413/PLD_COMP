#ifndef DECLARATION_H
#define DECLARATION_H

#include "Ligne.h"
#include "Enums.h"
#include <string>

class Declaration : public Ligne
{
	public:
	Declaration();
	Declaration(Type* t, std::string* name);
	
	protected:
	Type* type;
	std::string* name;
		
};

#endif
