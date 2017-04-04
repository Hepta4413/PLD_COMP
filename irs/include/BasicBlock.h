#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <vector>
#include <string>
#include <iostream>
//#include "CFG.h"
#include "IRInstr.h"

//class IRInstr;
class CFG;

using namespace std;

class BasicBlock
{
	public:
	BasicBlock();
	BasicBlock(CFG* cfg, string entry_label);
	void gen_asm(ostream &o);
	void add_IRInstr(IRInstr::Mnemo op, Type t, vector<string> params);
	int get_var_index(string name);
	
	private:
	vector<IRInstr*> irinstrs;
	BasicBlock * exit_true;
	BasicBlock * exit_false;
	CFG * cfg;
	string label;
	
};

#endif
