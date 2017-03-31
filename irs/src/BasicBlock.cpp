#include "BasicBlock.h"

BasicBlock::BasicBlock()
{
	
}

BasicBlock::BasicBlock(CFG* c, string entry_label)
{
	cfg = c;
	label = entry_label;
}

void BasicBlock::gen_asm(ostream &o)
{
	
}

void BasicBlock::add_IRInstr(IRInstr::Mnemo op, Type t, vector<string> params)
{
	IRInstr * ir = new IRInstr(this, op, t, params);
	irinstrs.push_back(ir);
}
