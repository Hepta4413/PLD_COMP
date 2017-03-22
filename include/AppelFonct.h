#ifndef APPELFONCT_H
#define APPELFONCT_H

#include "Fonction.h"
#include "Expression.h"

class AppelFonct : public Expression
{
	public:
	AppelFonct();
	AppelFonct(Fonction f, Expression[] param);
	
	private:
	Fonction fonction;
	Expression[] parametres;
		
};

#endif
