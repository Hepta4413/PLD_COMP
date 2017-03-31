#ifndef IRINSTR_H
#define IRINSTR_H

#include <string>
#include <vector>
#include "Type.h"
#include <iostream>
#include "BasicBlock.h"

using namespace std;

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

class IRInstr
{
	public:
	IRInstr();
	IRInstr(BasicBlock* bb_, Mnemo mn, Type t, Vector<string> params);
	void gen_asm(ostream &o);
	
	private:
	BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	Mnemo mnemo;
	long cons;
	Vector<string> regs;
	Type t;
}

#endif
