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
	Type calculType ();
	Fonction* getFonctionAssocie();
	void setFonctionAssocie(Fonction* f);
	bool verifAppelFonction();
	string buildIR(CFG * cfg);

	private:
	std::string* fonction;
	std::vector<Expression*>* parametres;
	Fonction* fonctionAssocie;
};

#endif
