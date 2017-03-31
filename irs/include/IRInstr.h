#ifndef IRINSTR_H
#define IRINSTR_H

#include <string>
#include <vector>
#include <iostream>
#include "Enums.h"
//#include "BasicBlock.h"

using namespace std;

class BasicBlock;

class IRInstr
{
	public:
	enum Mnemo{	ldconst,
			add,
			sub,
			mul,
			rmem,
			wmem,
			call, 
			cmp_eq,
			cmp_lt,
			cmp_le };
	
	IRInstr();
	IRInstr(BasicBlock* bb_, Mnemo mn, Type t, vector<string> params);
	void gen_asm(ostream &o);
	
	private:
	BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	Mnemo mnemo;
	long cons;
	vector<string> regs;
	Type t;
};

#endif
