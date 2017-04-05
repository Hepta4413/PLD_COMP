#include "BasicBlock.h"
#include "CFG.h"

BasicBlock::BasicBlock()
{
	irinstrs= new vector<IRInstr*>();
	label = "TROLOLO";
}

BasicBlock::BasicBlock(CFG* c)
{
	cfg = c;
	irinstrs= new vector<IRInstr*>();
	label = "TROLOLO";
}

BasicBlock::BasicBlock(CFG* c, string entry_label)
{
	cfg = c;
	label = entry_label;
	irinstrs= new vector<IRInstr*>();
	label = "TROLOLO";
}

void BasicBlock::gen_asm(ostream &o)
{
	#ifdef MAP
		cout<<"Appel a la fonction gen_asm de BasicBloc"<<endl;
	#endif
	for(unsigned int i = 0 ; i<irinstrs->size() ; i++)
	{
		irinstrs->at(i)->gen_asm(o);
	}
}

void BasicBlock::add_IRInstr(IRInstr::Mnemo op, Type t, vector<string> params)
{
	#ifdef MAP
		cout<<"Appel a la fonction add_IRInstr de BasicBloc"<<endl;
	#endif
	IRInstr * ir = new IRInstr(this, op, t, params);
	cout<<"MILIEU add_IRInstr "<<endl;
	cout << label << endl;
	irinstrs->push_back(ir);
	cout<<"FIN add_IRInstr"<<endl;

}

int BasicBlock::get_var_index(string name)
{
	return cfg->get_var_index(name);
}
