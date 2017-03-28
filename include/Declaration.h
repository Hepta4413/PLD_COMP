#ifndef DECLARATION_H
#define DECLARATION_H

#include "Ligne.h"
#include "Enums.h"
#include <string>

using namespace std;

class Declaration : public Ligne
{
	public:
	Declaration();
	Declaration(Type t, string* name);
	string* getName();

	protected:
	Type type;
	string* name;

};

#endif
