#ifndef DECLARATION_H
#define DECLARATION_H

#include "Ligne.h"
#include "Type.h"

using namespace std;

class Declaration : public Ligne
{
	public:
	Declaration();
	
	private:
	Type type;
		
};

#endif
