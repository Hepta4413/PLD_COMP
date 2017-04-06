#include "CFG.h"

CFG::CFG()
{
	current_bb = new BasicBlock(this);
	bbs.push_back(current_bb);
}

CFG::CFG(Fonction* f)
{
	current_bb = new BasicBlock(this);
	bbs.push_back(current_bb);
	ast = f;
	nextFreeSymbolIndex=-8;

	cout << "------Construction CFG nextFreeSymbolIndex : " << nextFreeSymbolIndex << endl;
}

void CFG::gen_asm(ostream &o)
{
	#ifdef MAP
		cout<<"Appel a la fonction gen_asm de CFG"<<endl;
	#endif
	gen_asm_prologue(o);

	//Génération du code asm pour chaque BB
	for(unsigned int i=0 ; i < bbs.size(); i++)
	{
		bbs[i]->gen_asm(o);
		printf("generation du bbs %i\n",i);
	}

	gen_asm_epilogue(o);
}

void CFG::gen_asm_prologue(ostream &o)
{
	int size = -(nextFreeSymbolIndex+8);

	cout << "--------------Size : " << to_string(size) << endl;

	string code = "";
	if (size > 0)
	{
		if (size%2==1)
			size++;
		code += *(ast->getNom());
		code += ":\n";
		code += "\tpushq %rbp\n";
		code += "\tmovq %rsp, %rbp\n";
		code += "\tsubq $";
		code += to_string(size);
		code += ", %rsp\n";
	}

	o << code;
}

void CFG::gen_asm_epilogue(ostream &o)
{
	o << "\tleave\n";
	o << "\tret\n\n";
}

//Pas nécessaire pour le moment
string CFG::IR_reg_to_asm(string reg)
{
	return "OK";
}

void CFG::add_to_symbol_table(string name, Type t)
{
	#ifdef MAP
		cout << "Appel a la fonction add_to_symbol_table de CFG " <<name<< endl;
	#endif
	symbolType.insert(pair<string, Type>(name,t));

	symbolIndex.insert(pair<string, int>(name,nextFreeSymbolIndex));
	nextFreeSymbolIndex-=8;
	cout<<"FIN"<<endl;
}

string CFG::create_new_tempvar(Type t)
{
	#ifdef MAP
		cout << "Appel a la fonction create_new_tempvar de CFG " << endl;
	#endif
	string reg = "!r"+(-nextFreeSymbolIndex);
	add_to_symbol_table(reg, t);

	return reg;
}

int CFG::get_var_index(string name)
{
	#ifdef MAP
		cout << "	Appel a la fonction get_var_index de CFG " <<name<< endl;
	#endif
	/*cout<<"afficher map"<<endl;
	for(auto i=symbolIndex.begin(); i!=symbolIndex.end() ; i++)
	{
		cout<<i->first<<endl;
	}*/
	return symbolIndex.at(name);

}

Type CFG::get_var_type(string name)
{
	return symbolType.at(name);
}

void CFG::add_bb(BasicBlock* bb)
{
	bbs.push_back(bb);
}

void CFG::createNewBasicBlock() {
	BasicBlock* b =  new BasicBlock(this);
	add_bb(b);
	current_bb = b;
}
