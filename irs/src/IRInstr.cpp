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
	cout << "Mnemo : "<<mnemo<< endl;
	switch(mnemo)
	{
		//var <- const
		case LDCONST:
			o << "\tmovq $" + regs[0] + ",\t" + offset(regs[1]) + "(%rbp)\n";
			break;

		//var <- var1+var2
		case ADD:
			o << "\tmovq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\taddq " + offset(regs[2]) + "(%rbp),\t%rax\n";
			o << "\tmovq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var <- var1-var2
		case SUB:
			o << "\tmovq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\tsubq " + offset(regs[2]) + "(%rbp),\t%rax\n";
			o << "\tmovq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var <- var1*var2
		case MUL:
			o << "\tmovq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\timulq " + offset(regs[2]) + "(%rbp)\n";
			o << "\tmovq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//var1 <- (var2)
		case RMEM:
			o << "\tmovq " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\tmovq %rax,\t" + offset(regs[0]) + "(%rbp)\n";
			break;

		//(var1) <- var2
		case WMEM:
			cout<<"WMEM "<<regs[0]<<regs[1]<<endl;
			o << "\tmovq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "\tmovq %rax,\t"+offset(regs[1])+"(%rbp)\n";
			break;

		//var <- call label (var1, var2, var3...)
		case CALL:
			//gestion séparée du putchar
			if(regs[0] == "putchar")
			{
				cout<<"PUTCHAR"<<endl;
				o << "\tmovl " + offset(regs[2]) + "(%rbp),\t%edi\n";
			}
			else
			{
				for(unsigned int i = 2 ; i < regs.size() ; i++)
				{
					o << "\tmovq %" + offset(regs[i]) + ","+to_string(-8*i)+"(%rbp)\n";
				}
			}

			o << "\tcall "+regs[0] + "\n";
			o << "\tmovq %rax,\t"+offset(regs[1])+"(%rbp)\n";
			break;

		//var1==var2
		case CMP_EQ:
			o << "\tmovq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "\tcmp " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\tjne " + regs[2] +"\n";
			break;

		//var1<var2
		case CMP_LT:
			o << "\tmovq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "\tcmp " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\tjge " + regs[2] +"\n";
			break;

		//var1<=var2
		case CMP_LE:
			o << "\tmovq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "\tcmp " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\tjg " + regs[2] +"\n";
			break;

		//fin d'un if + début else
		case ENDIF:
			o << "\tjmp " + regs[0] + "\n";
			o << regs[1] + ":\n";
			break;

		//fin d' else
		case LABEL:
			o << regs[0] + ":\n";
			break;

		//fin d'un while ou d'un for
		case ENDWHILEFOR:
			o << "\tjmp " + regs[0] + "\n";
			o << regs[1] + ":\n";
			break;
			
		case CMP_NEQ:
			o << "\tmovq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "\tcmp " + offset(regs[1]) + "(%rbp),\t%rax\n";
			o << "\tje " + regs[2] +"\n";
			break;
			
		case RETURN:
			o << "\tmovq " + offset(regs[0]) + "(%rbp),\t%rax\n";
			o << "\tleave\n\tret\n"
			break;
		
	}
}

string IRInstr::offset(string n)
{
	cout<< "IRInstr::offset : " << to_string(bb->get_var_index(n))<<endl;
	return to_string((bb->get_var_index(n)));
}
