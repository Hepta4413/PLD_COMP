#ifndef SYMBOL_H
#define SYMBOL_H

#include <vector>
#include <string>

enum TypeS{VAR,FUNCT};
enum TypeVar{INT64, INT32, CHAR};
enum Scope{FUNCT_PARAM, FOR_STATE, BLOCK_LOCAL}

class Symbol
{
	public:
	Symbol();
	
	private:
	string name;
	TypeS typeS;
	TypeVar typeVar;
	Scope scope;
	int nbParam;
	TypeS typesParam[];
}

#endif
