#ifndef APPELFONCT_H
#define APPELFONCT_H

#include "Fonction.h"
#include "Expression.h"
#include <vector>


class AppelFonct : public Expression
{
	public:
	AppelFonct();
	AppelFonct(Fonction f, vector<Expression> param);
	
	private:
	Fonction fonction;
	vector<Expression> parametres;
		
};

#endif
