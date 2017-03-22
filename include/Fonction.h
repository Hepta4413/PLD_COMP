#ifndef FONCTION_H
#define FONCTION_H

#include "Var.h"
#include "Programme.h"

class Fonction
{
	public:
	Fonction();
	Fonction(Var[] arg, Programme p);
	
	private:
	Var[] arguments;
	Programme prog;
};

#endif
