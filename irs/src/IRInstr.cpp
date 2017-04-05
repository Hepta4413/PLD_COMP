#include "IRInstr.h"
#include "BasicBlock.h"

IRInstr::IRInstr()
{

}

IRInstr::IRInstr(BasicBlock* bb_, Mnemo mn, Type type, vector<string> params)
{
	#ifdef MAP
		cout << "Appel au constructeur de IRInstr "<< endl;
	#endif
	bb = bb_;
	mnemo = mn;
	t = type;
	regs = params;
}

void IRInstr::gen_asm(ostream &o)
{
	#ifdef MAP
		cout << "Appel a la fonction gen_asm de IRInstr "<< endl;
	#endif
	cout << "mnemo "<<mnemo<< endl;
	switch(mnemo)
	{
		//var <- const
		case LDCONST:
			cout <<"movq $" + regs[0] + ",\t%" + offset(regs[1]) + "\n"<<endl;
			o << "movq $" + regs[0] + ",\t%" + offset(regs[1]) + "\n";
			break;

		//var <- var1+var2
		case ADD:
			o << "movq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "addq " + offset(regs[2]) + "(%rbp),\t%rax\n";
			o << "movq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var <- var1-var2
		case SUB:
			o << "movq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "subq " + offset(regs[2]) + "(%rbp),\t%rax\n";
			o << "movq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var <- var1*var2
		case MUL:
			o << "movq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "imulq " + offset(regs[2]) + "(%rbp)\n";
			o << "movq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var1 <- (var2)
		case RMEM:
			o << "movq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "movq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//(var1) <- var2
		case WMEM:
			cout<<"WMEM "<<regs[0]<<regs[1]<<endl;
			o << "movq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "movq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "movq %r10,\t(%rax)\n";
			break;

		//var <- call label (var1, var2, var3...)
		case CALL:
			//gestion séparée du putchar
			if(label == "putchar")
				o << "movl %" + offset(regs[1]) + "(%rbp),\t(%edi)\n";
			else
			{
				for(unsigned int i = 1 ; i < regs.size() ; i++)
				{
					o << "movq %" + regs[i] + ","+to_string(-8*i)+"(%rbp)\n";
				}
			}
			
			o << "call "+label + "\n";
			break;

		//var1=var2
		case CMP_EQ:
			o << "movq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "cmp " + offset(regs[1]) + "(%rbp),\ŧ%rax\n";
			o << "je " + label +"\n";
			break;

		//var1<var2
		case CMP_LT:
			o << "movq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "cmp " + offset(regs[1]) + "(%rbp),\ŧ%rax\n";
			o << "jl " + label +"\n";
			break;

		//var1<=var2
		case CMP_LE:
			o << "movq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "cmp " + offset(regs[1]) + "(%rbp),\ŧ%rax\n";
			o << "jle " + label +"\n";
			break;
	}
}

string IRInstr::offset(string n)
{
	cout<<to_string(bb->get_var_index(n))<<endl;
	return to_string(-(bb->get_var_index(n)));
}
