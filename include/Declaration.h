 #ifndef DECLARATION_H
#define DECLARATION_H

#include "Ligne.h"
#include "Expression.h"
#include <string>
#include "Bloc.h"
#include "VarS.h"
#include "OPBinaire.h"

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
	void AddName(string* name);
	void setBlocDeclaration(Bloc* b);
	void setLvalue(bool b);
	bool getLvalue();
	void setRvalue(bool b);
	bool getRvalue();
  string buildIR(CFG * cfg);

	protected:
	Type type;
	string* name;
	Expression* tailleTab;
	bool lvalue;
	bool rvalue;

};

#endif
