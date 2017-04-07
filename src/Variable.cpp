#include "Variable.h"
#include "Bloc.h"
#include "Declaration.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include <iostream>

using namespace std;

Variable::Variable()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Variable" << endl;
	#endif
	typeContenu = _VAR;
}

void Variable::VerifDeclaration(string* nom)
{
	#ifdef MAP
		cout << "Appel au constructeur de Variable(string* nom)" << endl;
	#endif
	Declaration* decl = blocParent->RechercherDeclaration(nom);
    if(decl==NULL){
		cerr<<"Erreur la variable "<<*nom<<" n'est pas déclarée"<<endl;
	}else{
		type=decl->getDeclarationType();
	}
	typeContenu = _VAR;
}

vector<Variable*> Variable::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de variable" << endl;
	#endif
	vector<Variable*> result;
	result.push_back(this);
	return result;
}

string* Variable::getNom()
{
	#ifdef MAP
		cout << "Appel a la fonction getNom de variable" << endl;
	#endif
	return nom;
}

bool Variable::getLvalue()
{
	#ifdef MAP
		cout << "Appel a la fonction getLvalue de variable" << endl;
	#endif
	return lvalue;
}

void Variable::setLvalue(bool lval)
{
	#ifdef MAP
		cout << "Appel a la fonction setRvalue de variable" << endl;
	#endif
	lvalue=lval;
}

bool Variable::getRvalue()
{
	#ifdef MAP
		cout << "Appel a la fonction getRvalue de variable" << endl;
	#endif
	return rvalue;
}

void Variable::setRvalue(bool rval)
{
	#ifdef MAP
		cout << "Appel a la fonction setLvalue de variable" << endl;
	#endif
	rvalue=rval;
}

void Variable::setType(Type t)
{
	#ifdef MAP
		cout << "Appel a la fonction setType de variable" << endl;
	#endif
	type=t;
}

Type Variable::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction calculType de variable" << endl;
	#endif
	return type;
}

string Variable::buildIR(CFG * cfg) {
	#ifdef MAP
		cout << "Appel a la fonction calculType de variable" << endl;
	#endif
	/*if(lvalue) {
		cout<<"SALUT"<<endl;
		string reg = cfg->create_new_tempvar(type);
		cout<<"SALUT"<<endl;
		int offset = cfg->get_var_index(reg);
		cout<<"SALUT"<<endl;
		vector<string> regs;
		regs.push_back(to_string(offset));
		cout<<"SALUT"<<endl;
		regs.push_back(reg);
		cout<<"SALUT"<<endl;
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, type, regs);
		cout<<"SALUT"<<endl;
		// reg <- !bp + reg
		//cfg->current_bb->add_IRInstr(IRInstr::Mnemo::LDCONST, calculType(), regs);
		return reg;
	}
	else {
		return "";
	}*/
	cout<<"AJOUT DE "<<*nom<<endl;
	cfg->add_to_symbol_table(*nom, type);
	return *nom;

}

void Variable::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de Variable" << endl;
	#endif
    blocParent = blc;
}
