#ifndef DECLARATION_H
#define DECLARATION_H

#include "Ligne.h"
#include "Expression.h"
#include <string>
#include "Bloc.h"
#include "VarS.h"

using namespace std;

class Declaration : public Ligne
{
	public:
	Declaration();
	Declaration(Expression* taille);
	Declaration(Type t, string* name);

	string* getName();

	Type getDeclarationType();
	void AddInfos(Type t, string* name);
	void setBlocDeclaration(Bloc* b);

	protected:
	Type type;
	string* name;
	Expression* tailleTab;

};

#endif
