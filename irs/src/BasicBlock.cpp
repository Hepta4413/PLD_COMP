#include "BasicBlock.h"
#include "CFG.h"

BasicBlock::BasicBlock()
{
	irinstrs= new vector<IRInstr*>();
	label = "";
}

BasicBlock::BasicBlock(CFG* c)
{
	cfg = c;
	irinstrs= new vector<IRInstr*>();
	label = "";
}

BasicBlock::BasicBlock(CFG* c, string entry_label)
{
	cfg = c;
	label = entry_label;
	irinstrs= new vector<IRInstr*>();
	label = "";
}

void BasicBlock::gen_asm(ostream &o)
{
	#ifdef MAP
		cout<<"Appel a la fonction gen_asm de BasicBloc "<<irinstrs->size()<<endl;
	#endif
	for(unsigned int i = 0 ; i<irinstrs->size() ; i++)
	{
		cout<<i<<endl;
		irinstrs->at(i)->gen_asm(o);
	}
}

void BasicBlock::add_IRInstr(IRInstr::Mnemo op, Type t, vector<string> params)
{
	#ifdef MAP
		cout<<"Appel a la fonction add_IRInstr de BasicBloc"<<endl;
	#endif
	IRInstr * ir = new IRInstr(this, op, t, params);
	irinstrs->push_back(ir);
}

int BasicBlock::get_var_index(string name)
{
	return cfg->get_var_index(name);
}
