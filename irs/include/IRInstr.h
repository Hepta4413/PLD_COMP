#ifndef IRINSTR_H
#define IRINSTR_H

#include <string>
#include <vector>

enum Mnemo{CONST_IN_VAR, VARPLUSVAR_IN_VAR, CALL_IN_VAR, VARBRACES_IN_VAR VAR_IN_VARBRACES};

class IRInstr
{
	public:
	IRInstr();
	void genAsm();
	
	private:
	CFG * cfg;
	Mnemo mnemo;
	long cons;
	Vector<string> regs[];
	
}

#endif
