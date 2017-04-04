#include "CFG.h"

CFG::CFG()
{

}

CFG::CFG(Fonction* f)
{
	ast = f;
	nextFreeSymbolIndex=f->getSize()*8;
}

void CFG::gen_asm(ostream &o)
{
	gen_asm_prologue(o);

	//Génération du code asm pour chaque BB
	for(unsigned int i=0 ; i < bbs.size(); i++)
	{
		current_bb = bbs[i];

		current_bb->gen_asm(o);
	}

	gen_asm_epilogue(o);
}

void CFG::gen_asm_prologue(ostream &o)
{
	int size = 0;
	string code = "";
	if (size > 0)
	{
		if (size%2==1)
			size++;
		//code += ast->getNom()
		code += "nomfnc";
		code += ":\n";
		code += "\tpushq %rbp\n";
		code += "\tmovq %rsp, %rbp\n";
		code += "\tsubq $";

		//Calcul de la size de la fonction
		size = ast->getSize();

		code += to_string(size*8);
		code += ", %rsp\n";
	}

	o << code;
}

void CFG::gen_asm_epilogue(ostream &o)
{
	o << "leave\n";
	o << "ret\n";
}

string CFG::IR_reg_to_asm(string reg)
{
	return "OK";
}

void CFG::add_to_symbol_table(string name, Type t)
{
	symbolType.insert(pair<string, Type>(name,t));

	symbolIndex.insert(pair<string, int>(name,nextFreeSymbolIndex));
	nextFreeSymbolIndex-=8;
}

string CFG::create_new_tempvar(Type t)
{
	string reg = "!r"+nextBBnumber;
	add_to_symbol_table(reg, t);

	return reg;
}

int CFG::get_var_index(string name)
{
	return symbolIndex.at(name);

}

Type CFG::get_var_type(string name)
{
	return symbolType.at(name);;
}

void CFG::add_bb(BasicBlock* bb)
{
	bbs.push_back(bb);
}
