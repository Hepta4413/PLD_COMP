#ifndef OPBINAIRE_H
#define OPBINAIRE_H

#include "Enums.h"

using namespace std;

class OPBinaire {
	private :
	OPBinaire(Expression e1, Expression e2, Opbinaire op);
		
	public :
	Expression e1;
	Expression e2;
	Opbinaire op;
	
};

#endif


