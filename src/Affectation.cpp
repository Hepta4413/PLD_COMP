#include "Affectation.h"
#include "Variable.h"
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
	vars = var;
	valuei = value;
	index = i;
	operateur=op;
	typeContenu = _AFFECTATION;
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
		cerr<<"Warning ligne "<<getLigne()<<" : "<<getColonne()
			<<" affectation d'un type différent "<<*(vars->getNom())<<" est de type "<<typeVar<<" pas du type "<<typeExpr<<endl;
		return typeVar;
	}
}

