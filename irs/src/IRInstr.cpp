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
			o << "movq $" + cons +",\t%" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var <- var1+var2
		case ADD:
		o << "movq %" + offset(regs[1]) + "(%rbp),\t%" + offset(regs[0]) + "(%rbp)\n";
		o << "addq %" + offset(regs[2]) + "(%rbp),\t%" + offset(regs[0]) + "\n";
			break;

		//var <- var1-var2
		case SUB:
		o << "movq %" + offset(regs[1]) + "(%rbp),\t%" + offset(regs[0]) + "(%rbp)\n";
		o << "subq %" + offset(regs[2]) + "(%rbp),\t%" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var <- var1*var2
		case MUL:
		o << "movq %" + offset(regs[1]) + "(%rbp),\t%rax\n";
		o << "imulq %" + offset(regs[2]) + "(%rbp)\n";
		o << "movq %rax,\t%" + offset(regs[0]) + "(%rbp)\n"; 
			break;

		//var1 <- (var2)
		case RMEM:

			break;

		//(var1) <- var2
		case WMEM:

			break;

		//var <- call label (var1, var2, var3...)
		case CALL:
			for(unsigned int i = 1 ; i < regs.size() ; i++)
			{
				o << "pushq %" + regs[i] + "\n";
			}
			o << "call "+ label + "\n";
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
}

int IRInstr::offset(string n) {
	return 0;
}
