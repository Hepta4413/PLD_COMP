#include "IRInstr.h"

IRInstr::IRInstr()
{
	
}

IRInstr::IRInstr(BasicBlock* bb_, Mnemo mn, Type type, vector<string> params)
{
	bb = bb_;
	mnemo = mn;
	t = type;
	regs = params;
}

void IRInstr::gen_asm(ostream &o)
{
	
}
