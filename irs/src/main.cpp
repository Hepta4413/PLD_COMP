#include <fstream>
#include <string>
#include <iostream>
#include "Fonction.h"
#include "Enums.h"
#include "CFG.h"

using namespace std;

void gen_prologue(ostream &o)
{
	o<<".text\n";
	o<<".global main\n\n";
}

void gen_epilogue(ostream &o)
{
	o<< "\tleave \n\tret\n";
}

int main()
{
	string* s = new string("test"); 
	Fonction* f = new Fonction(INT64_T, s, NULL, NULL);
	CFG* cfg = new CFG(f);
	
	
	//Ouverture du fichier assembleur
	ofstream codeAs("main.s", ios::out | ios::trunc);
	
	if(codeAs)
	{	
		gen_prologue(codeAs);
		printf("Prologue généré\n");
		
		//cfg->gen_asm(codeAs);
		printf("Corps généré\n");
		
		gen_epilogue(codeAs);
		printf("Epilogue généré\n");
		
		codeAs.close();
	}
	else
		cerr << "Cannot open file" << endl;
		
		
	delete s;
	delete f;
	delete cfg;
		
	return 0;
	
}
