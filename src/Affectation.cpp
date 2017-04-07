#include "Affectation.h"
#include "Variable.h"
#include "../irs/include/CFG.h"
#include "../irs/include/IRInstr.h"
#include <vector>
#include <iostream>

using namespace std;

Affectation::Affectation()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Affectation" << endl;
	#endif
	typeContenu = _AFFECTATION;
}

Affectation::Affectation(Variable* var, Expression* value, Opbinaire op)
{
	#ifdef MAP
		cout << "Appel au constructeur de Affectation(Variable* var, Expression* value, Opbinaire op)" << endl;
	#endif
	var->setLvalue(true);
	if(op==EQUAL_OB)
	{
		var->setRvalue(false);
	}
	vars = var;
	valuei = value;
	operateur=op;
	typeContenu = _AFFECTATION;
}

Affectation::Affectation(VarTab* var, Expression* value, int i, Opbinaire op)
{
	#ifdef MAP
		cout << "Appel au constructeur de Affectation(VarTab* var, Expression* value, int i, Opbinaire op)" << endl;
	#endif
	var->setLvalue(true);
	if(op==EQUAL_OB)
	{
		var->setRvalue(false);
	}
	vars = var;
	valuei = value;
	index = i;
	operateur=op;
	typeContenu = _AFFECTATION;
}

void Affectation::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de Affectation" << endl;
	#endif
    blocParent = blc;
    valuei->setBloc(blc);
    vars->setBloc(blc);
}

vector<Variable*> Affectation::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de Affectation" << endl;
	#endif
	vector<Variable*> result;
	result.push_back(vars);
	vector<Variable*> resultIntermediaire = valuei->variableUtilise();
	result.insert( result.end(), resultIntermediaire.begin(), resultIntermediaire.end() );
	return result;
}


Type Affectation::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction calculType de Affectation" << endl;
	#endif
	Type typeVar = vars->getType();
	Type typeExpr = valuei->calculType();
	if(typeExpr==CONSTVAL_T || typeVar == typeExpr){
		type=typeVar;
		return typeVar;
	}
	else
	{
		#ifdef WAR
		cerr<<"Warning ligne "<<getLigne()<<" : "<<getColonne()
			<<" affectation d'un type différent "<<*(vars->getNom())<<" est de type "<<typeVar<<" pas du type "<<typeExpr<<endl;
		#endif
		return typeVar;
	}
}

string Affectation::buildIR(CFG * cfg)
{
	#ifdef MAP
		cout << "Appel a la fonction buildIR de Affectation" << endl;
	#endif
	string right = *(vars->getNom())/*vars->buildIR(cfg)*/;
	string left = valuei->buildIR(cfg);
	vector<string> regs;
	switch (operateur) {
		case EQUAL_OB:


			regs.push_back(left);
			regs.push_back(right);

			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::WMEM, calculType(), regs);
		break;
		case PLUSEQUAL_OB:
			regs.push_back(right);
			regs.push_back(left);
			regs.push_back(right);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::ADD, calculType(), regs);

		break;
		case MINUSEQUAL_OB:
			regs.push_back(right);
			regs.push_back(left);
			regs.push_back(right);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::SUB, calculType(), regs);
		break;
		case MULTEQUAL_OB:
			regs.push_back(right);
			regs.push_back(left);
			regs.push_back(right);
			cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
		/*
		case DIVEQUAL_OB:
		cfg->current_bb->add_IRInstr(IRInstr::Mnemo::MUL, calculType(), regs);
		break;
			*/
	}
	return right;


}
