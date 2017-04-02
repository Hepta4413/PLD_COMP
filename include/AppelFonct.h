#ifndef APPELFONCT_H
#define APPELFONCT_H

#include "Fonction.h"
#include "Expression.h"
#include <vector>
#include "Enums.h"

class AppelFonct : public Expression
{
	public:
	AppelFonct();
	AppelFonct(std::string* f, std::vector<Expression*>* param);
	vector<Variable*> variableUtilise();
	vector<Expression*>* getParam();
	string* getNom();
	
	private:
	std::string* fonction;
	std::vector<Expression*>* parametres;
};

#endif
