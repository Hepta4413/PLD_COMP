#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include "Enums.h"

class Variable : public Expression
{
	public:
	Variable();
	Variable(Type t, std::string n);
	void AddInfo(Type t, std::string n);
	
	private:
	Type type;
	std::string nom;
		
};

#endif
