#include <fstream>
#include <string>
#include <iostream>

using namespace std;

string gen_prologue(string name, int size)
{
	string code = "";
	if (size > 0)
	{
		if (size%2==1)
			size++;
		code += name+":\n";
		code += "\tpushq %rbp\n";
		code += "\tmovq %rsp, %rbp\n";
		code += "\tsubq $";
		code += to_string(size*8);
		code += ", %rsp\n";
	}
	return code;
}

string gen_epilogue()
{
	return "\tleave \n\tret\n";
}

int main()
{
	ofstream codeAs("main2.s", ios::out | ios::trunc);
	
	if(codeAs)
	{
		codeAs<<".text\n";
		codeAs<<".global main\n\n";
		
		
		codeAs<<gen_prologue("toto", 3);
		codeAs<<gen_epilogue();
		
		codeAs<<"main:\n\n";
		codeAs<<"\tretq\n\n";
		
		codeAs.close();
	}
	else
		cerr << "Cannot open file" << endl;
		
	return 0;
	
}
