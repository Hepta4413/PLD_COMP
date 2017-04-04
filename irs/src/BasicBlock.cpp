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
	for(unsigned int = 0 ; i<irinstrs.size() ; i++)
	{
		irinstrs[i]->gen_asm(o);
	}
}

void BasicBlock::add_IRInstr(IRInstr::Mnemo op, Type t, vector<string> params)
{
	IRInstr * ir = new IRInstr(this, op, t, params);
	irinstrs.push_back(ir);
}

int BasicBlock::get_var_index(string name)
{
	cfg->get_var_index(name);
}
