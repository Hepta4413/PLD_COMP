#include "IRInstr.h"

IRInstr::IRInstr()
{
	
}

IRInstr::IRInstr(BasicBlock* bb_, Mnemo mn, Type type, Vector<string> params)
{
	bb = bb_;
	mnemo = mn;
	t = type;
	regs = param;
}

void IRInstr::gen_asm(ostream &o)
{
	
}
