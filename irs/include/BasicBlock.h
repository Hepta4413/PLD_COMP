#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <vector>
#include <string>
#include <iostream>
#include "IRInstr.h"

//class IRInstr;
class CFG;

using namespace std;

class BasicBlock
{
	public:
	BasicBlock();
	BasicBlock(CFG* cfg);
	BasicBlock(CFG* cfg, string entry_label);
	void gen_asm(ostream &o);
	void add_IRInstr(IRInstr::Mnemo op, Type t, vector<string> params);
	int get_var_index(string name);

	BasicBlock * exit_true;
	BasicBlock * exit_false;

	private:
	vector<IRInstr*> irinstrs;
	CFG * cfg;
	string label;

};

#endif
