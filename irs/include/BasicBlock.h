#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <vector>

class BasicBlock
{
	public:
	BasicBlock();
	void genAsm();
	
	private:
	Vector<IRIstr> irinstrs;
	BasicBlock * nextIncond;
	BasicBlock * nextCond;
	CFG * cfg;
	
}

#endif
