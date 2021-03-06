#ifndef CFG_H
#define CFG_H

#include <vector>
#include <string>
#include <iostream>
#include "Fonction.h"
#include "Enums.h"
#include "BasicBlock.h"

//class BasicBlock;

using namespace std;

class CFG
{
	public:
	CFG();
	CFG(Fonction* ast);

	Fonction* ast; /**< The AST this CFG comes from */

	void add_bb(BasicBlock* bb);
	void createNewBasicBlock();

	// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
	void gen_asm(ostream& o);
	string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
	void gen_asm_prologue(ostream& o);
	void gen_asm_epilogue(ostream& o);

	// symbol table methods
	void add_to_symbol_table(string name, Type t);
	string create_new_tempvar(Type t);
	int get_var_index(string name);
	Type get_var_type(string name);

	// basic block management
	string new_BB_name();
	BasicBlock* current_bb;

	protected:
	map <string, Type> symbolType; /**< part of the symbol table  */
	map <string, int> symbolIndex; /**< part of the symbol table  */
	int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
	int currentBBnumber; /**< just for naming */

	vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/

};

#endif
