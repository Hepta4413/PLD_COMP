#ifndef VARIABLE_H
#define VARIABLE_H

#include "Enums.h"

class Variable
{
	public:
	Variable(Type t, int64_t val);
	Variable(Type t, int32_t val);
	Variable(Type t, char c);
	
	private:
	Type type;
	int64_t valeurint64;
	int32_t valeurint32;
	char c;
		
};

#endif
