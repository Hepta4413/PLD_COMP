#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BasicBlock
{
	public:
	BasicBlock(CFG* cfg, string entry_label);
	void gen_asm(ostream &o);
	void add_IRInstr(IRInstr::Mnemo op, Type t, vector<string> params);
	
	private:
	Vector<IRIstr*> irinstrs;
	BasicBlock * exit_true;
	BasicBlock * exit_false;
	CFG * cfg;
	string label;
	
}

#endif
