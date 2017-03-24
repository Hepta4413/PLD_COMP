#ifndef APPELFONCT_H
#define APPELFONCT_H

#include "Fonction.h"
#include "Expression.h"
#include <vector>

class AppelFonct : public Expression
{
	public:
	AppelFonct();
	AppelFonct(Fonction f, std::vector<Expression> param);
	
	private:
	Fonction fonction;
	std::vector<Expression> parametres;
		
};

#endif
