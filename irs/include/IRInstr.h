#ifndef IRINSTR_H
#define IRINSTR_H

#include <string>
#include <vector>
#include <iostream>
#include "Enums.h"


using namespace std;

class BasicBlock;

class IRInstr
{
	public:
	enum Mnemo{	LDCONST,
				ADD,
				SUB,
				MUL,
				RMEM,
				WMEM,
				CALL,
				CMP_EQ,
				CMP_LT,
				CMP_LE };

	IRInstr();
	IRInstr(BasicBlock* bb_, Mnemo mn, Type t, vector<string> params);
	void gen_asm(ostream &o);
	string offset(string n);
	
	private:
	BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	Mnemo mnemo;
	long cons;
	vector<string> regs;
	Type t;
	string label;
};

#endif
