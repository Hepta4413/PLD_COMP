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
	switch(mnemo)
	{
		//var <- const
		case LDCONST:
			o << "movq $" + cons +",\t%" + regs[0] + "\n";
			break;
		
		//var <- var1+var2
		case ADD:
			o << "movq %" + regs[1] + ",\t%" + regs[0] + "\n";
			o << "addq %" + regs[2] + ",\t%" + regs[0] + "\n";
			break;
			
		//var <- var1-var2
		case SUB:
			o << "movq %" + regs[1] + ",\t%" + regs[0] + "\n";
			o << "subq %" + regs[2] + ",\t%" + regs[0] + "\n";
			break;
			
		//var <- var1*var2
		case MUL:
			o << "movq %" + regs[1] + ",\t%" + regs[0] + "\n";
			o << "imulq %" + regs[2] + ",\t%" + regs[0] + "\n";
			break;
			
		//var1 <- (var2)
		case RMEM:
			
			break;
			
		//(var1) <- var2
		case WMEM:
			
			break;
			
		//var <- call label (var1, var2, var3...)
		case CALL:
			
			break;
			
		//var <- var1=var2
		case CMP_EQ:
			
			break;
			
		//var <- var1<var2
		case CMP_LT:
			
			break;
			
		//var <- var1<=var2
		case CMP_LE:
			
			break;
	}
