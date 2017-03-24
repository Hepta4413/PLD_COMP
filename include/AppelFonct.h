#ifndef APPELFONCT_H
#define APPELFONCT_H

#include "Fonction.h"
#include "Expression.h"
#include <vector>


class AppelFonct : public Expression
{
	public:
	AppelFonct();
	AppelFonct(std::string f, vector<Expression> param);
	
	private:
	std::string fonction;
	vector<Expression> parametres;
		
};

#endif
