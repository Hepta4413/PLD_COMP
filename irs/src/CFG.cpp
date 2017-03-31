#include "CFG.h"

CFG::CFG()
{
	
}

CFG::CFG(Fonction* f)
{
	ast = f;
	nextFreeSymbolIndex=8;
}

void CFG::gen_asm(ostream &o)
{
	int size = 0;
	string code = "";
	if (size > 0)
	{
		if (size%2==1)
			size++;
		//code += ast->nom+":\n";
		code += "\tpushq %rbp\n";
		code += "\tmovq %rsp, %rbp\n";
		code += "\tsubq $";
		
		//Calcul de la size de la fonction
		size = ast->getSize();
		
		code += to_string(size*8);
		code += ", %rsp\n";
	}
}

void CFG::gen_asm_prologue(ostream &o)
{
	
}

void CFG::gen_asm_epilogue(ostream &o)
{
	
}

string CFG::IR_reg_to_asm(string reg)
{
	return "OK";
}

void CFG::add_to_symbol_table(string name, Type t)
{
	symbolType.insert(pair<string, Type>(name,t));
	
	symbolIndex.insert(pair<string, int>(name,nextFreeSymbolIndex));
	nextFreeSymbolIndex+=8;
}

string CFG::create_new_tempvar(Type t)
{
	return "OK";
	
}

int CFG::get_var_index(string name)
{
	return 0;
	
}

Type CFG::get_var_type(string name)
{
	return INT64_T;
}
