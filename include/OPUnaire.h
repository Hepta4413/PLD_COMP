#ifndef OPUNAIRE_H
#define OPUNAIRE_H

#include "Enums.h"

using namespace std;

class OPUnaire {
	private :
	OPUnaire(Expression e, Opunaire op);
		
	public :
	Expression exp;
	Opunaire op;
	
};

#endif

